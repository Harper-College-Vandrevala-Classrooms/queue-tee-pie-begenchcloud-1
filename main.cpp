#include <iostream>
#include <string>
using namespace std;

class Cutie {
public:
    virtual string description() = 0;
    virtual int cuteness_rating() = 0;
    virtual ~Cutie() {}
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }
    int cuteness_rating() override {
        return 11;
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A fluffy kitten with a tiny meow";
    }
    int cuteness_rating() override {
        return 10;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny pygmy marmoset hanging on a branch";
    }
    int cuteness_rating() override {
        return 9;
    }
};

class QueueTees {
private:
    static const int MAX_SIZE = 10;
    Cutie* queue[MAX_SIZE];
    int front;
    int rear;
    int current_size;

public:
    QueueTees() : front(0), rear(-1), current_size(0) {}

    void enqueue(Cutie& cutie) {
        if (current_size == MAX_SIZE) {
            cout << "Queue is full! Cannot add more cuties.\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = &cutie;
        current_size++;
    }

    Cutie* dequeue() {
        if (current_size == 0) {
            cout << "Queue is empty! No cuties to dequeue.\n";
            return nullptr;
        }
        Cutie* cutie = queue[front];
        front = (front + 1) % MAX_SIZE;
        current_size--;
        return cutie;
    }

    int size() const {
        return current_size;
    }
};

int main() {
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    QueueTees queue;

    cout << "Initial queue size: " << queue.size() << endl;

    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    cout << "Queue size after adding cuties: " << queue.size() << endl;

    Cutie* dequeued = queue.dequeue();
    if (dequeued) {
        cout << "Dequeued: " << dequeued->description() << " (Cuteness: " << dequeued->cuteness_rating() << ")\n";
    }

    dequeued = queue.dequeue();
    if (dequeued) {
        cout << "Dequeued: " << dequeued->description() << " (Cuteness: " << dequeued->cuteness_rating() << ")\n";
    }

    dequeued = queue.dequeue();
    if (dequeued) {
        cout << "Dequeued: " << dequeued->description() << " (Cuteness: " << dequeued->cuteness_rating() << ")\n";
    }

    cout << "Final queue size: " << queue.size() << endl;

    return 0;
}
