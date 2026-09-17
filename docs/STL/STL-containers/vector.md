## Vector

## What is a vector ?

* A `Vector` is a dynamic array whose size can be changed during the runtime.

## How does it work ?

* **Simple Vector Class Structure:**

```cpp
template<typename T>

class vector {
private:
    T* m_data = nullptr;    //points at the first element.
    T* m_size = nullptr;    //points at the end of valid element.
    T* m_capacity = nullptr;    //points at the end of the allocated memory.
}
```

* **Visual Diagram:**
*   **Consider the following vector:**
    ```cpp
    vector<int> vec(10);
    for(int i = 1; i <= 5; i++) push_back(10 * i);
    ```
*   This is how it would look like at memory level:

*   [10][20][30][40][50][NA][NA][NA][NA][NA]
      ^               ^                   ^
      |               |                   |
    m_data          m_size            m_capacity