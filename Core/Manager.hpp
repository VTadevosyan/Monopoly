#ifndef MANAGER_HPP
#define MANAGER_HPP


namespace Core {

class Engine;

class Manager
{
public:
    static void create();
    static void destroy();
    static Manager* get();

private:
    static Manager* sInstance;

private:
    /// @brief Constructor
    Manager();

    /// @brief Destructor
    ~Manager();

public:
    /// @brief Gets the engine
    const Engine* getEngine() const noexcept;

    /// @brief Gets the engine
    Engine* getEngine() noexcept;

private:
    Engine* mEngine = nullptr;
};

} /// Core namespace

#endif // MANAGER_HPP
