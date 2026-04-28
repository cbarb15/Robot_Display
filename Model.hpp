#ifndef MODEL_HPP
#define MODEL_HPP

using namespace std;

class ModelListener;

class Model
{
public:
    Model();

    enum BLEStatus
    {
    	CONNECTED = 1,
    	DISCONNECTED,
    	SEARCHING
    };

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void setBLEStatus(BLEStatus newStatus) {
    		bleStatus = newStatus;
        }

    BLEStatus getBLEStatus() {
    	return bleStatus;
    }

    void tick();
protected:
    ModelListener* modelListener;


private:
    BLEStatus bleStatus;
};

#endif // MODEL_HPP
