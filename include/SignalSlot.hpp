#include <iostream>
#include <functional>
#include <vector>

// 信号类
template <typename... Args>
class Signal {
public:
    using Slot = std::function<void(Args...)>;

    // 绑定槽函数
    void connect(const Slot& slot) {
        slots.push_back(slot);
    }

    // 触发信号
    void emit(Args... args) {
        for (const auto& slot : slots) {
            slot(args...);
        }
    }

private:
    std::vector<Slot> slots;
};

// 槽函数
void mySlot(int value) {
    std::cout << "Slot called with value: " << value << std::endl;
}
