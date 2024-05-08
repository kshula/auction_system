#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for representing a bid
struct Bid {
    string bidderName;
    double amount;

    Bid(const string& name, double bidAmount)
        : bidderName(name), amount(bidAmount) {}
};

// Define an AuctionItem class to represent items being auctioned
class AuctionItem {
private:
    string itemName;
    double startingPrice;
    vector<Bid> bids;
    bool isOpen;

public:
    AuctionItem(const string& name, double startPrice)
        : itemName(name), startingPrice(startPrice), isOpen(true) {}

    const string& getItemName() const { return itemName; }
    double getCurrentPrice() const {
        if (bids.empty()) {
            return startingPrice;
        } else {
            return bids.back().amount; // Return the amount of the last bid
        }
    }

    bool isOpenForBidding() const { return isOpen; }

    // Function to place a bid on the item
    bool placeBid(const string& bidderName, double bidAmount) {
        if (isOpen && bidAmount > getCurrentPrice()) {
            bids.push_back(Bid(bidderName, bidAmount));
            cout << "Bid placed by " << bidderName << " for $" << bidAmount << endl;
            return true;
        } else {
            cout << "Bid not accepted for " << itemName << " by " << bidderName << endl;
            return false;
        }
    }

    // Function to close the auction
    void closeAuction() {
        isOpen = false;
        cout << "Auction for " << itemName << " is closed." << endl;
    }

    // Function to display the winning bid
    void displayWinningBid() const {
        if (!bids.empty()) {
            const Bid& winningBid = bids.back(); // Get the last (highest) bid
            cout << "Winning bid for " << itemName << ": $" << winningBid.amount
                 << " by " << winningBid.bidderName << endl;
        } else {
            cout << "No bids placed for " << itemName << endl;
        }
    }
};

int main() {
    // Create an auction item
    AuctionItem painting("Famous Painting", 1000.0);

    // Place bids on the item
    painting.placeBid("Bidder1", 1200.0);
    painting.placeBid("Bidder2", 1500.0);
    painting.placeBid("Bidder3", 1300.0);

    // Close the auction
    painting.closeAuction();

    // Display the winning bid
    painting.displayWinningBid();

    return 0;
}
