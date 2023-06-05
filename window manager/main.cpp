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
private:
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
        if (!windows.empty()) {
            windows.pop_back();
            std::cout << "Window closed." << std::endl;
        } else {
            std::cout << "No window available to close." << std::endl;
        }
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
        std::cout << "Enter a command ('add', 'move', 'resize', 'display', 'close'): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Enter the x-coordinate of the window: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate of the window: ";
            std::cin >> y;
            std::cout << "Enter the width of the window: ";
            std::cin >> width;
            std::cout << "Enter the height of the window: ";
            std::cin >> height;

            Window window(x, y, width, height);
            monitor.addWindow(window);
        } else if (command == "move") {
            // Move window logic
        } else if (command == "resize") {
            // Resize window logic
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
