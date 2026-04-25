#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>

using namespace std;

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void setBLEStatus(string newStatus) {
    		bleStatus = newStatus;
        }

    string getBLEStatus() {
    	return bleStatus;
    }

    void tick();
protected:
    ModelListener* modelListener;


private:
    string bleStatus;
};

#endif // MODEL_HPP
