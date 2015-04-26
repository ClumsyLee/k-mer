#include <cstdint>
#include <string>

typedef int_least32_t Row;

class KmerTree
{
 public:
    // Construct a KmerTree with a max row length.
    KmerTree(int k, int max_row_length);
    ~KmerTree();

    // Insert a row into the KmerTree.
    // Use const char * here, becasuse every row has a fixed length,
    //     using std::string here might be a little bit wasteful.
    void Insert(const char *row);

    // Done with inserting, prepare for searching.
    void InsertDone();

    // Search a certain sequence in the KmerTree.
    // `InsertDone()` must has been called after the last insertion.
    // Return true if the sequence exists, false otherwise.
    bool Search(const std::string &sequence, Row &row, int &pos) const;
};
