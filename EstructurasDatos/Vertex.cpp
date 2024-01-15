#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
private:
    int number;
    int weigth;

public:
    Vertex(int number, int weigth):number(number), weigth(weigth){}
    Vertex(){}

    int getNumber() const{
        return number;
    }

    void setNumber(int number){
        this->number=number;
    }

    double getWeigth() const{
        return weigth;
	}

    void setWeigth(double weigth) {
        this->weigth = weigth;
	}

    bool operator>=(const Vertex &other){
        return weigth>=other.weigth;
    }

    bool operator>(const Vertex &other){
        return weigth>other.weigth;
    }

    bool operator<=(const Vertex &other){
        return weigth<=other.weigth;
    }

    bool operator<(const Vertex &other){
        return weigth<other.weigth;
    }

    bool operator==(const Vertex &other){
        return weigth==other.weigth;
    }
};

#endif