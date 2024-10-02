#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ProducerConsumer {
public:
    ProducerConsumer() : done(false) {}

    void produce(const std::function<void(int)>& callback) {
        for (int i = 0; i < 10; ++i) {
            {
                std::unique_lock<std::mutex> lock(mutex);
                queue.push(i);
            }
            callback(i); // Call the callback function with the produced value
            cv.notify_one();
        }
        {
            std::unique_lock<std::mutex> lock(mutex);
            done = true;
        }
        cv.notify_one();
    }

    void consume(const std::function<void(int)>& callback) {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this](){ return !queue.empty() || done; });

            if (done && queue.empty()) {
                break;
            }

            int value = queue.front();
            queue.pop();
            callback(value); // Call the callback function with the consumed value
        }
    }

private:
    std::queue<int> queue;
    std::mutex mutex;
    std::condition_variable cv;
    bool done;
};

int main() {
    ProducerConsumer pc;

    auto produceCallback = [](int value) {
        std::cout << "Produced: " << value << std::endl;
    };

    auto consumeCallback = [](int value) {
        std::cout << "Consumed: " << value << std::endl;
    };

    std::thread producer([&pc, &produceCallback]() { pc.produce(produceCallback); });
    std::thread consumer([&pc, &consumeCallback]() { pc.consume(consumeCallback); });

    producer.join();
    consumer.join();

    return 0;
}
