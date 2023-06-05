#include <iostream>
#include <vector>

class Window {
private:
    int x;        // X-coordinate of the window's upper left corner
    int y;        // Y-coordinate of the window's upper left corner
    int width;    // Width of the window
    int height;   // Height of the window

public:
    Window(int initialX, int initialY, int initialWidth, int initialHeight)
            : x(initialX), y(initialY), width(initialWidth), height(initialHeight) {}

    void move(int deltaX, int deltaY) {
        x += deltaX;
        y += deltaY;
        std::cout << "Window moved to (" << x << ", " << y << ")" << std::endl;
    }

    void resize(int newWidth, int newHeight) {
        if (newWidth >= 0 && newHeight >= 0) {
            width = newWidth;
            height = newHeight;
            std::cout << "Window resized to " << width << "x" << height << std::endl;
        } else {
            std::cout << "Invalid dimensions. Window size cannot be negative." << std::endl;
        }
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }
};

class Monitor {
public:
    std::vector<Window> windows;

public:
    bool empty() const {
        return windows.empty();
    }

    void addWindow(const Window& window) {
        windows.push_back(window);
        std::cout << "Window added." << std::endl;
    }

    void closeWindow() {
        windows.pop_back();
        std::cout << "Window closed." << std::endl;
    }

    void displayScreen() const {
        for (int row = 0; row < 50; ++row) {
            for (int col = 0; col < 80; ++col) {
                bool windowPixel = false;
                for (const auto& window : windows) {
                    if (col >= window.getX() && col < window.getX() + window.getWidth() &&
                        row >= window.getY() && row < window.getY() + window.getHeight()) {
                        windowPixel = true;
                        break;
                    }
                }
                std::cout << (windowPixel ? "1 " : "0 ");
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Monitor monitor;
    int x, y, width, height;

    while (true) {
        std::string command;
        std::cout << "Enter a command ('move', 'resize', 'display', 'close'): ";
        std::cin >> command;

        if (command == "move") {
            int deltaX, deltaY;
            std::cout << "Enter the amount to move in the X direction: ";
            std::cin >> deltaX;
            std::cout << "Enter the amount to move in the Y direction: ";
            std::cin >> deltaY;

            if (!monitor.empty()) {
                int index;
                std::cout << "Enter the index of the window to move: ";
                std::cin >> index;

                if (index >= 0 && index < monitor.windows.size()) {
                    monitor.windows[index].move(deltaX, deltaY);
                } else {
                    std::cout << "Invalid window index." << std::endl;
                }
            } else {
                std::cout << "No window available. Please add a window first." << std::endl;
            }
        } else if (command == "resize") {
            int newWidth, newHeight;
            std::cout << "Enter the new width: ";
            std::cin >> newWidth;
            std::cout << "Enter the new height: ";
            std::cin >> newHeight;

            if (!monitor.empty()) {
                int index;
                std::cout << "Enter the index of the window to resize: ";
                std::cin >> index;

                if (index >= 0 && index < monitor.windows.size()) {
                    monitor.windows[index].resize(newWidth, newHeight);
                } else {
                    std::cout << "Invalid window index." << std::endl;
                }
            } else {
                std::cout << "No window available. Please add a window first." << std::endl;
            }
        } else if (command == "display") {
            monitor.displayScreen();
        } else if (command == "close") {
            monitor.closeWindow();
            if (monitor.empty()) {
                std::cout << "All windows closed. Exiting the program." << std::endl;
                break;
            }
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
