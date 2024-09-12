#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

// A Huffman tree node
class MinHeapNode {
public:
    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    shared_ptr<MinHeapNode> left, right;

    MinHeapNode(char data, unsigned freq)
        : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// For comparison of two heap nodes (needed in min heap)
struct Compare {
    bool operator()(const shared_ptr<MinHeapNode>& l, const shared_ptr<MinHeapNode>& r) {
        return (l->freq > r->freq);
    }
};

// Prints Huffman codes from the root of Huffman Tree
void printCodes(shared_ptr<MinHeapNode> root, string str) {
    if (!root) return;

    // If this is a leaf node
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and prints codes by traversing the built Huffman Tree
void HuffmanCodes(const vector<char>& data, const vector<int>& freq) {
    // Create a min heap & inserts all characters of data[]
    priority_queue<shared_ptr<MinHeapNode>, vector<shared_ptr<MinHeapNode>>, Compare> minHeap;

    for (size_t i = 0; i < data.size(); ++i) {
        minHeap.push(make_shared<MinHeapNode>(data[i], freq[i]));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        shared_ptr<MinHeapNode> left = minHeap.top();
        minHeap.pop();

        shared_ptr<MinHeapNode> right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        shared_ptr<MinHeapNode> top = make_shared<MinHeapNode>('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}

// Driver Code
int main() {
    vector<char> arr = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freq = { 5, 9, 12, 13, 16, 45 };

    HuffmanCodes(arr, freq);

    return 0;
}
