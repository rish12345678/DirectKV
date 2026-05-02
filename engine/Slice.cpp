class Slice {
public:
    // Basic constructors
    Slice() : data_(""), size_(0) {}
    Slice(const char* d, size_t n) : data_(d), size_(n) {}
    Slice(const std::string& s) : data_(s.data()), size_(s.size()) {}
    Slice(const char* s) : data_(s), size_(strlen(s)) {}

    // Data accessors
    const char* data() const { return data_; }
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    // Array-style access
    char operator[](size_t n) const {
        return data_[n]; 
    }

    void clear() { data_ = ""; size_ = 0; }

    // Comparison is just memcmp
    int compare(const Slice& b) const {
        const size_t min_len = (size_ < b.size_) ? size_ : b.size_;
        int r = memcmp(data_, b.data_, min_len);
        if (r == 0) {
            if (size_ < b.size_) r = -1;
            else if (size_ > b.size_) r = 1;
        }
        return r;
    }

private:
    const char* data_;
    size_t size_;
};