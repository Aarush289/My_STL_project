#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Book
{
public:
    std ::string title;
    std ::string author;
private:
    std::string isbn;
    int copiesAvailable;
    int totalCopies;

public:
   
    Book(std::string title, std::string author, std::string isbn, int copiesAvailable, int totalCopies)
        : title(title), author(author), isbn(isbn), copiesAvailable(copiesAvailable), totalCopies(totalCopies) {}
    Book() : title("UnknownTitle"), author("UnknownAuthor"), isbn("ISBN"), copiesAvailable(0), totalCopies(5) {}
    Book(const Book &other, const std::string &new_isbn)
        : title(other.title), author(other.author), isbn(new_isbn), copiesAvailable(other.copiesAvailable), totalCopies(other.totalCopies) {}
    std ::string getISBN() const
    {
        return isbn;
    }
    int getCopiesAvailable() const
    {
        return copiesAvailable;
    }
    int getTotalCopies() const
    {
        return totalCopies;
    }
    void updateCopies(int count)
    {
        if (copiesAvailable + count < 0 || totalCopies + count < 0)
        {
            std::cout << "Invalid request! Count becomes negative." << std::endl;
            return;
        }
        copiesAvailable += count;
        totalCopies += count;
        return;
    }
    bool borrowBook()
    {
        if (copiesAvailable <= 0)
        {
            std::cout << "Invalid request! Copy of book not available" << std::endl;
            return false;
        }
        copiesAvailable--; // Decrease the available copies
        return true;
    }
    bool returnBook()
    {
        if (copiesAvailable >= totalCopies)
        {
            std::cout << "Invalid request! Copy of book exceeds total copies" << std::endl;
            return false;
        }
       copiesAvailable++; // Increase the available copies
        return true;
    }
    void printDetails() const
    {
        std::cout << title << " " << author << std::endl;
    }
};

class Member
{


private:
    std::string memberID;
public:
    std ::string name;
private:
    int borrowLimit;
    std::map<std::string, int> borrowedBooks;
   

public:
    
    Member(std::string memberID, std ::string name, int borrowLimit)
        : memberID(memberID), name(name), borrowLimit(borrowLimit) {}

    Member(std ::string memberID, std ::string name)
        : memberID(memberID), name(name), borrowLimit(5) {}
    std ::string getMemberID() const
    {
        return memberID;
    }
    bool borrowBook(const std::string &isbn)
    {
        int count = 0;
        for (auto &book : borrowedBooks)
        {
            count += book.second;
        }

        if (count >= borrowLimit)
        {
            std::cout << "Invalid request! Borrow Limit exceeded" << std::endl;
            return false;
        }

        borrowedBooks[isbn]++; // Increment the count of borrowed books
        return true;
    }

    bool returnBook(const std::string &isbn)
    {
        if (borrowedBooks[isbn] <= 0)
        {
            std::cout << "Invalid request! Book not borrowed" << std::endl;
            return false;
        }
        borrowedBooks[isbn]--; // Decrement the count of borrowed books
        return true;
    }

    void printDetails() const
    {
        int count = 0;
        for (auto &book : borrowedBooks)
        {
            count += book.second;
        }
        if (count == 0)
        {
            return;
        }
        for (const auto &book : borrowedBooks)
        {   if(book.second <= 0)
            {
                continue; // Skip if no copies are borrowed
            }
            std::cout << memberID << " "
                      << name << " "
                      << book.first << " "
                      << book.second << std::endl;
        }
    }
};

class library
{
private:
    std ::vector<Book> books;
    std ::vector<Member> members;

public:
    bool addBook(const Book &book)
    {
        for (const auto &b : books)
        {
            if (b.getISBN() == book.getISBN())
            {
                std::cout << "Invalid request! Book with same isbn already exists" << std::endl;
                return false;
            }
        }
        books.push_back(book);
        return true;
    }
    bool registerMember(const Member &member)
    {
        for (const auto &m : members)
        {
            if (m.getMemberID() == member.getMemberID())
            {
                std::cout << "Invalid request! Member with same id already exists" << std::endl;
                return false;
            }
        }
        members.push_back(member);
        return true;
    }
    bool borrowBook(const std::string &memberID, const std::string &isbn)
    {
        for (auto &member : members)
        {
            if (member.getMemberID() == memberID)
            {
                for (auto &book : books)
                {
                    if (book.getISBN() == isbn)
                    {
                        if (book.getCopiesAvailable() <= 0)
                        {
                            std::cout << "Invalid request! Copy of book not available" << std::endl;
                            return false;
                        }
                        if (!member.borrowBook(isbn))
                        {
                            //  book.returnBook(); // Rollback if member cannot borrow
                            return false;
                        }
                        if (!book.borrowBook())
                        {
                            return false;
                        }
                        // book.updateCopies(-1); // Decrease the available copies
                        return true;
                    }
                }
                //  std:: cout << "Invalid request! Book not found" << std:: endl;
                return false;
            }
        }
        //  std:: cout << "Invalid request! Member not found" << std:: endl;
        return false;
    }
    bool returnBook(const std::string &memberID, const std::string &isbn)
    {
        for (auto &member : members)
        {
            if (member.getMemberID() == memberID)
            {
                for (auto &book : books)
                {
                    if (book.getISBN() == isbn)
                    {
                        if (!book.returnBook())
                        {
                            return false;
                        }
                        if (!member.returnBook(isbn))
                        {
                            book.borrowBook(); // Rollback if member cannot return
                            return false;
                        }
                        //  book.updateCopies(1); // Increase the available copies
                        return true;
                    }
                }
                //  std:: cout << "Invalid request! Book not found" << std:: endl;
                return false;
            }
        }
        //  std:: cout << "Invalid request! Member not found" << std:: endl;
        return false;
    }
    std::vector<Book> getBooks() const
    {
        return books;
    }
    std::vector<Member> getMembers() const
    {
        return members;
    }
    void updateCopies(const std::string &isbn, int count)
    {
        for (auto &book : books)
        {
            if (book.getISBN() == isbn)
            {
                book.updateCopies(count);
                return;
            }
        }
        std::cout << "Invalid request! Book not found" << std::endl;
    }
    void printLibraryDetails() const
    {
        for (const auto &book : books)
        {
            std::cout << book.title << " "
                      << book.author << " "
                      << book.getCopiesAvailable() << std::endl;
        }
        for (const auto &member : members)
        {
            std::cout << member.getMemberID() << " "
                      << member.name << std::endl;
        }
    }
};

int main()
{
    library lib;
    while (1)
    {
        std::string str;
        std::getline(std::cin, str);
        if (str.empty())
        {
            continue; // Skip empty lines
        }
        if (str == "Done")
        {
            break; // Exit the loop if "Done" is entered
        }
        if (str == "Book")
        {
            std::string title, author, isbn;
            int copiesAvailable, totalCopies;
            std::cin >> title;
            if (title == "None")
            {
                Book book;
                lib.addBook(book);
            }
            else
            {
                if (title == "ExistingBook")
                {
                    std ::string old_ISBN;
                    std::cin >> old_ISBN;
                    std ::cin >> isbn;
                    for (const auto &book : lib.getBooks())
                    {
                        if (book.getISBN() == old_ISBN)
                        {
                            Book newBook(book, isbn);
                            lib.addBook(newBook);
                            break;
                        }
                    }
                }
                else
                {
                    std::cin >> author >> isbn >> copiesAvailable >> totalCopies;
                    Book book(title, author, isbn, copiesAvailable, totalCopies);
                    lib.addBook(book);
                }
            }
        }
        if (str == "UpdateCopiesCount")
        {
            std::string isbn;
            int count;
            std::cin >> isbn >> count;
            lib.updateCopies(isbn , count);
        }
        if (str == "Member")
        {
            std::string memberID;
            std::cin >> memberID;
            if (memberID == "NoBorrowLimit")
            {
                std::string id, name;
                std::cin >> id >> name;
                Member member(id, name);
                lib.registerMember(member);
            }
            else
            {
                std::string name;
                int borrowLimit;
                std::cin >> name >> borrowLimit;
                Member member(memberID, name, borrowLimit);
                lib.registerMember(member);
            }
        }
        if (str == "Borrow")
        {
            std::string memberID, isbn;
            std::cin >> memberID >> isbn;
            lib.borrowBook(memberID, isbn);
        }
        if (str == "Return")
        {
            std::string memberID, isbn;
            std::cin >> memberID >> isbn;
            lib.returnBook(memberID, isbn);
        }
        if (str == "PrintBook")
        {
            std::string isbn;
            std::cin >> isbn;
            for (const auto &book : lib.getBooks())
            {
                if (book.getISBN() == isbn)
                {
                    book.printDetails();
                    break;
                }
            }
        }
        if (str == "PrintMember")
        {
            std::string memberID;
            std::cin >> memberID;
            for (const auto &member : lib.getMembers())
            {
                if (member.getMemberID() == memberID)
                {
                    member.printDetails();
                    break;
                }
            }
        }
        if (str == "PrintLibrary")
        {
            lib.printLibraryDetails();
        }
    }
    return 0;
}