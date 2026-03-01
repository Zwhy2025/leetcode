
#include <iostream>
#include <atomic>
namespace utils {

    template<typename T>
    class SharedPtr {

    public:
        explicit SharedPtr(T* p = nullptr) : _tPtr(p), _nRefCount(nullptr) {
            if (_tPtr) {
                std::cout << "creat!" << std::endl;
                _nRefCount = new std::atomic<int>(1);
            }

        }

        SharedPtr(const SharedPtr& other) :_tPtr(other._tPtr), _nRefCount(other._nRefCount) {
            if (_nRefCount) {
                std::cout << "& ++!" << std::endl;
                ++(*_nRefCount);
            }

        }

        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                release();
                _tPtr = other._tPtr;
                _nRefCount = other._nRefCount;
                if (_nRefCount) {
                    std::cout << "== ++!" << std::endl;
                    ++(*_nRefCount);
                }
            }
            return *this;
        }


        ~SharedPtr() {
            release();
        }

        T* operator*() const {
            return _tPtr;
        }


        T* operator->() const {
            return _tPtr;
        }

        int UseCount() const {
            return _nRefCount ? _nRefCount->load() : 0;
        }

    private:
        void release() {
            if (_nRefCount && --(*_nRefCount) == 0) {
                delete _tPtr;
                delete _nRefCount;
                std::cout << "released!" << std::endl;
            }
        }

    private:

        T* _tPtr;
        std::atomic<int>* _nRefCount;
    };



} // namespace utils
