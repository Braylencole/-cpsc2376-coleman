### Program Specification

This program is a lightweight system designed to manage the lending operations of a local board game café. It will allow the user to keep track of all available board games, including the number of copies in stock, and monitor which customer has borrowed which game and when it is due back. Users will be able to view a list of all games, check out games to customers, and record when games are returned. The main entities involved are games, customers, and lending records.

### 1) Nouns and Verbs

## Nouns

- Game
- Customer
- Lending Record
- GameID
- CustomerID
- DueDate
- Name
- AvailableCopies

## Verbs

- Add Game
- View all games
- Check out game
- return game
- View lending records

### 2) Classes


```cpp

class Game {
public:
    Game(int id, std::string name, int totalCopies);

    int getId() const;
    std::string getName() const;
    int getAvailableCopies() const;
    void checkoutCopy();
    void returnCopy();

private:
    int gameId;
    std::string name;
    int availableCopies;
};



class LendingRecord {
public:
    LendingRecord(int recordId, int gameId, int customerId, std::string dueDate);

    int getRecordId() const;
    int getGameId() const;
    int getCustomerId() const;
    std::string getDueDate() const;

private:
    int recordId;
    int gameId;
    int customerId;
    std::string dueDate;
};


class Customer {
public:
    Customer(int id, std::string name);

    int getId() const;
    std::string getName() const;

private:
    int customerId;
    std::string name;
};

```
---

### 3) Class Diagram

```mermaid

classDiagram
    class Game {
        +getId() int
        +getName() string
        +getAvailableCopies() int
        +checkoutCopy() void
        +returnCopy() void
    }

    class Customer {
        +getId() int
        +getName() string
    }

    class LendingRecord {
        +getRecordId() int
        +getGameId() int
        +getCustomerId() int
        +getDueDate() string
    }

    LendingRecord --> Game : references
    LendingRecord --> Customer : references

    ```
