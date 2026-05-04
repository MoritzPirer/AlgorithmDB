//
// A ring buffer (also called circle buffer / circular buffer) is a data structure that
// implements a fixed size container as if it were connected end to end
//
// TAGS:
// domain/data-structure
//

#include <stddef.h>
#include <algorithm>
#include <mutex>

template <size_t BUFFER_SIZE>
class RingBuffer
{
private:
  unsigned char data_[BUFFER_SIZE] = {0};
  size_t read_pos_ = 0;
  size_t write_pos_ = 0;
  size_t size_ = 0;
  std::mutex buffer_lock_;

public:
    RingBuffer() = default;
    RingBuffer(const RingBuffer& other) {
        this->data_ = other.data_;
        this->read_pos_ = other.read_pos_;
        this->write_pos_ = other.write_pos_;
        this->size_ = other.size_;
        this->buffer_lock_ = std::mutex();
    } 
    ~RingBuffer() = default;

    /// @brief consumes up to n bytes from the buffer and writes them to destination.
    ///   If there are less than n bytes to read, as many bytes as possible are read.
    /// @param destination a pointer to where the bytes are written.
    ///   Caller must ensure the pointer stays valid until the function returns
    /// @param n how many bytes to read at most
    /// @return the amount of bytes actually read
    ///   (0 if the buffer was empty, n if it had at least n bytes in it or somewhere in between)
    size_t read(char* destination, size_t n) {
        buffer_lock_.lock();
        if (size_ == 0) {
            buffer_lock_.unlock();
            // nothing to read
            return 0;
        }

        size_t bytes_to_read = std::min(n, size_);

        size_t bytes_before_wrap = BUFFER_SIZE - read_pos_;
        if (bytes_before_wrap > bytes_to_read) {
            bytes_before_wrap = bytes_to_read;
        }

        memcpy(destination, data_ + read_pos_, bytes_before_wrap);

        size_t bytes_after_wrap = bytes_to_read - bytes_before_wrap;
        if (bytes_after_wrap > 0) {
            memcpy(destination + bytes_before_wrap, data_, bytes_after_wrap);
        }

        read_pos_ = (read_pos_ + bytes_to_read) % BUFFER_SIZE;
        size_ -= bytes_to_read;

        buffer_lock_.unlock();
        return bytes_to_read;
    }

    /// @brief writes up to n bytes from source into the buffer. If the buffer has less than n free bytes,
    ///   as many as possible are written
    /// @param source where to read the bytes from. Caller must ensure that source has at least n bytes to read and that
    ///   source remains a valid pointer until the function returns
    /// @param n how many bytes to write at most
    /// @return how many bytes were actually written
    ///   (0 if the buffer was full, n if everything was written, or somewhere in between)
    size_t write(const char* source, size_t n)
    {
        buffer_lock_.lock();
        if (size_ == BUFFER_SIZE) {
            // no room to write
            buffer_lock_.unlock();
            return 0;
        }

        size_t writable = BUFFER_SIZE - size_;
        size_t bytes_to_write = std::min(n, writable);

        size_t bytes_before_wrap = BUFFER_SIZE - write_pos_;
        if (bytes_before_wrap > bytes_to_write) {
            bytes_before_wrap = bytes_to_write;
        }

        memcpy(data_ + write_pos_, source, bytes_before_wrap);

        size_t bytes_after_wrap = bytes_to_write - bytes_before_wrap;
        if (bytes_after_wrap > 0) {
            memcpy(data_, source + bytes_before_wrap, bytes_after_wrap);
        }

        write_pos_ = (write_pos_ + bytes_to_write) % BUFFER_SIZE;
        size_ += bytes_to_write;

        buffer_lock_.unlock();
        return bytes_to_write;
    }

    /// @return true if all bytes in the buffer are free, i.e. there is nothing to read, false otherwise
    bool isEmpty() {
        buffer_lock_.lock();
        bool is_empty = (size_ == 0);
        buffer_lock_.unlock();

        return is_empty;
    }

    /// @return true if every byte in the buffer is currently in use, i.e. there is no room to write anyting,
    ///   false otherwise
    bool isFull() {
        buffer_lock_.lock();
        bool is_full = (size_ == BUFFER_SIZE);
        buffer_lock_.unlock();

        return is_full;
    }

    /// @brief returns the number of bytes the buffer can store
    size_t capacity() {
        return BUFFER_SIZE;
    }

    /// @brief calculates and returns the amount of readable bytes in the buffer, i.e. the number of
    ///   bytes that have been written but not yet read
    size_t countReadable() {
        return size_; // might need synchronization
    }

    /// @brief calculates and returns the amount of writable bytes in the buffer, i.e. the number of
    ///   bytes that can still be written before the buffer is full
    size_t countWritable() {
        buffer_lock_.lock();
        size_t writable = BUFFER_SIZE - size_;
        buffer_lock_.unlock();

        return writable;
    }
};