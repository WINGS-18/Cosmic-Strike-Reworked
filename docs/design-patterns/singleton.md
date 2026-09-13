## The Singleton Pattern

## What is a singleton?
* A singleton is a design pattern.
* Singleton ensures a class has only one instance.

## How it works
* **Single instance:** Ensures a class can have only one instance throughout the lifetime of the program.
* **Meyers Singleton:** In this game, I've implemented the Meyers Singleton.

```cpp
class Singleton {
private:    
    // 1. Private constructor ensures a class instance cannot be created outside this class
    Singleton(); 

public:
    // 2. Static method to access the single reference instance globally
    static Singleton& GetInstance() {
        static Singleton instance; // Allocated once in the static memory segment
        return instance;
    }
    
    // 3. Explicitly deleted copy operations to prevent duplication
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
```

* **Private constructor:** The constructor is kept under the `private` access specifier so that no objects can be created outside the class.
* **Static Keyword Significance:** Members or methods marked `static` belong to the class type itself, not to individual instances. Hence, we can call these methods without creating an object, using the scope resolution operator (`::`) instead.
* **Lazy Initialization:** The Meyers Singleton follows lazy initialization, meaning the static instance will be created only when the `GetInstance` function is called for the very first time.
* **Preventing Copying:** Since the singleton pattern is meant to have a single instance, copying it must not be allowed. We explicitly delete the **copy constructor** and the **copy assignment operator (`operator=`)**. 
* **The Copy Trap:** If we do not delete these, anyone from outside can write `auto copyInstance = Singleton::GetInstance();`. This would trigger a copy and create a second, separate instance in memory.


## ⚠️ Problems with Singletons

* **Permanent Memory Waste:** Because local static variables live in the static data segment, you can't free their memory midway through the game. They take up space from the second they are created until the whole program closes. So even if you're done using that instance you cannot delete it. Although there's way you can achieve deletion but you need to create instance using `new` keyword.
* **The Teardown Nightmare:** If you have multiple singletons linked like a tree, deleting a parent won't delete the children. C++ destroys statics in the reverse order they were made, so a parent singleton might destroy itself while a child still needs it, causing a crash when you exit the game.