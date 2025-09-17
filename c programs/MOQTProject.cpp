#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cstdint>


struct instrumentData{
    uint64_t instrumentID;
    double lasttradedprice;
    double diffdata;
};

class Publisher{
    public:
            virtual void update_data(uint64_t instrumentID ,double lasttradedprice,double additionaldata)=0;
            virtual void get_data(uint64_t subscriberID, uint64_t instrumentID)=0;
            virtual void subscribe(uint64_t subscriberID)=0;
            virtual ~Publisher()= default;
};
class EquityPublisher : public Publisher{
    std::unordered_map<uint64_t, instrumentData> instruments_;
    std::unordered_set<uint64_t> subscribers_;

public:
 void update_data(uint64_t instrumentID , double lasttradedprice,double lastDayVolume) override{
    if(instrumentID>=1000 || instrumentID<0){
       std::cout << "Invalid instrument ID for EquityPublisher" << std::endl;
    }
    else{
       instruments_[instrumentID] = {instrumentID,lasttradedprice,lastDayVolume};
    }
 }
 void subscribe(uint64_t subscriberID) override{
    subscribers_.insert(subscriberID);
 }

 void get_data(uint64_t subscriberID,uint64_t instrumentID) override{
    if(subscribers_.count(subscriberID)==0 || instruments_.count(instrumentID)==0){
       std:: cout<<"Invalid ID"<< std::endl;
    }
    else{
        instrumentData dataptr ;
        dataptr=instruments_.at(instrumentID);
       std:: cout<< "instrument ID: "<< dataptr.instrumentID << std::endl;
       std:: cout<< "lasttradedprice : "<< dataptr.lasttradedprice << std::endl;
       std:: cout<< "Last day volume: "<<dataptr.diffdata << std::endl;
    }
 }
};

class BondPublisher : public Publisher{
    std::unordered_map<uint64_t, instrumentData> instruments_;
    std::unordered_set<uint64_t> subscribers_;

    void update_data(uint64_t instrumentId, double lastTradedPrice, double bondYield) override {
        if (instrumentId < 1000 || instrumentId >= 2000) {
              std::  cout<<"invalid BondPublisherID"<< std::endl;
        }
        else{
            instruments_[instrumentId]={instrumentId,lastTradedPrice, bondYield};
        }
    }

    void subscribe(uint64_t subscriberID) override{
            subscribers_.insert(subscriberID);
    }

    void get_data(uint64_t subscriberID,uint64_t instrumentID){
             if (instrumentID < 1000 || instrumentID >= 2000) {
                std::cout << "Invalid ID"<< std::endl;
             }
             else{
                    instrumentData dataptr;
                    dataptr=instruments_.at(instrumentID);
                   std:: cout<< "instrument ID: "<< dataptr.instrumentID <<std::endl;
                  std::  cout<< "lasttradedprice : "<< dataptr.lasttradedprice << std::endl;
                   std:: cout<< "Bond Yield : "<<dataptr.diffdata <<std::endl;
             }
    }
};

class Subscriber {
    protected:
        std::unordered_map<uint64_t, std::shared_ptr<Publisher>> subscriptions_;
        uint64_t id_;
        char type_;

    public:
        Subscriber(uint64_t id, char type) : id_(id), type_(type) {}
        virtual void subscribe(uint64_t instrumentID, std::shared_ptr<Publisher> publisher) = 0;
        virtual void get_data(uint64_t instrumentID) = 0;
        virtual ~Subscriber() = default;

        char get_type() const { return type_; }
        uint64_t get_id() const { return id_; }
};

class PaidSubscriber : public Subscriber {
public:
    PaidSubscriber(uint64_t id) : Subscriber(id, 'P') {}

    void subscribe(uint64_t instrumentID, std::shared_ptr<Publisher> publisher) override {
        subscriptions_[instrumentID] = publisher;
        publisher->subscribe(id_);
    }

    void get_data(uint64_t instrumentID) override {
        if (subscriptions_.count(instrumentID) == 0) {
           std:: cout<< "Invalid ID" << std::endl;
        }
        else{
        subscriptions_[instrumentID]->get_data(id_, instrumentID);
        }
    }
};class FreeSubscriber : public Subscriber {
    int requestCount_;
    static const int MAX_REQUESTS = 100;

public:
    FreeSubscriber(uint64_t id) : Subscriber(id, 'F'), requestCount_(0) {}

    void subscribe(uint64_t instrumentId, std::shared_ptr<Publisher> publisher) override {
        subscriptions_[instrumentId] = publisher;
        publisher->subscribe(id_);
    }

    void get_data(uint64_t instrumentId) override {
        if (requestCount_ >= MAX_REQUESTS || subscriptions_.count(instrumentId) == 0) {
            printf("Invalid ID\n");
        }
        ++requestCount_;
         subscriptions_.at(instrumentId)->get_data(id_, instrumentId);
    }
};
class System {
    std::unordered_map<uint64_t, std::shared_ptr<Publisher>> publishers_;
    std::unordered_map<uint64_t, std::shared_ptr<Subscriber>> subscribers_;

public:
    void add_publisher(uint64_t instrumentId, std::shared_ptr<Publisher> publisher) {
        publishers_[instrumentId] = publisher;
    }

    void add_subscriber(std::shared_ptr<Subscriber> subscriber) {
        subscribers_[subscriber->get_id()] = subscriber;
    }

    void handle_request(const std::string& request) {
        std::istringstream iss(request);
        char type;
        iss >> type;

        if (type == 'P') { // Publisher update
            uint64_t instrumentId;
            double lastTradedPrice, diffdata;
            iss >> instrumentId >> lastTradedPrice >> diffdata;

            if (publishers_.count(instrumentId) == 0) {
                std::cerr << "Invalid publisher for instrumentId: " << instrumentId << "\n";
                return;
            }
            publishers_[instrumentId]->update_data(instrumentId, lastTradedPrice, diffdata);
        } else if (type == 'S') { // Subscriber request
            char subscriberType;
            uint64_t subscriberId, instrumentId;
            std::string action;
            iss >> subscriberType >> subscriberId >> action >> instrumentId;

            if (subscribers_.count(subscriberId) == 0) {
                std::cerr << "Invalid subscriberId: " << subscriberId << "\n";
                return;
            }

            auto subscriber = subscribers_[subscriberId];

            if (action == "subscribe") {
                if (publishers_.count(instrumentId) == 0) {
                    std::cerr << "Invalid publisher for instrumentId: " << instrumentId << "\n";
                    return;
                }
                subscriber->subscribe(instrumentId, publishers_[instrumentId]);
            } else if (action == "get_data") {
                instrumentData data;
                 subscriber->get_data(instrumentId);
            }
        }
    }
};
int main() {
    auto equityPublisher = std::make_shared<EquityPublisher>();
    auto bondPublisher = std::make_shared<BondPublisher>();
    auto system = System();

    // Adding publishers
    for (uint64_t i = 0; i < 1000; ++i) {
        system.add_publisher(i, equityPublisher);
    }
    for (uint64_t i = 1000; i < 2000; ++i) {
        system.add_publisher(i, bondPublisher);
    }

    // Adding subscribers but here I am assigning ID's 1 to 1000 to paid and 1000 to 2000 to free , this can be changed as per need .
    for(int i=0;i<1000;i++){ 
    auto paidSubscriber = std::make_shared<PaidSubscriber>(i);
    system.add_subscriber(paidSubscriber);
    }
    for(int i=1000;i<2000;i++){
    auto freeSubscriber = std::make_shared<FreeSubscriber>(i);
    
    system.add_subscriber(freeSubscriber);
    }
    // handle requests
    int n;
    std::cout << "Give No of commands : " ;
    std::cin >> n ;
    getchar();
    while(n--){
            char str[100];
            fgets(str,100,stdin);
            system.handle_request(str);
    }
    return 0;
}