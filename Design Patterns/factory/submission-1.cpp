class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* car = new Car();
        return car;
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* bike = new Bike();
        return bike;
    }
};

class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* truck = new Truck();
        return truck;
    }
};
