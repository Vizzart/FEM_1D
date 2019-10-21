#include <iostream>

struct Node {
    double x;
    int BC;
};

struct Element {
    int ID[2];
    double S, K, L;
    double HL[2][2];
    double* PL;
};

struct Grid {
    Node* nodes;
    Element* elements;
};

struct SOE {
    double** HG;
    double* PG;
    double* TG;
};

const double S = 2.0;
const double K = 50.0;
const double L = 5.0;
const double alpha = 10.0;
const double q = -150.0;
const double t_otoczenia = 400.0;

int nh = 3;


void initHL(Element *currentElement) {
    currentElement->HL[0][0] = (currentElement->S * currentElement->K) / currentElement->L;
    currentElement->HL[0][1] = -(currentElement->S * currentElement->K) / currentElement->L;
    currentElement->HL[1][0] = -(currentElement->S * currentElement->K) / currentElement->L;
    currentElement->HL[1][1] = (currentElement->S * currentElement->K) / currentElement->L;
}

void initPL(Element *currentElement) {
    currentElement->PL[0] = q * S;
    currentElement->PL[1] = 0.0;
    currentElement->PL[0] = - alpha * t_otoczenia * S;
}

/**************************************/
void printHG(double** array) {
    std::cout << std::endl;
    for (int i = 0; i < nh; i++) {
        for (int j = 0; j < nh; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}



int main() {
    double deltaX = L / (nh - 1);
    
    // Generating nodes
    Node* nodes = new Node[nh];
    for (int i = 0; i < nh; i++) {
        nodes[i].x = i * deltaX;

        if (i == 0)
            nodes[i].BC = 1;
        else if (i == (nh - 1))
            nodes[i].BC = 2;
        else
            nodes[i].BC = 3;
    }
//    for (int i = 0; i < nh; i++) {
//        std::cout << nodes[i].x << ", " << nodes[i].BC << std::endl;
//    }

    // Generating Elements
    Element* elements = new Element[nh -1];
    for (int i = 0; i < (nh - 1); i++) {
        Element* currentElement = &elements[i];
        currentElement->ID[0] = i + 1;
        currentElement->ID[1] = i + 2;
        currentElement->S = S;
        currentElement->K = K;
        currentElement->L = deltaX;
        initHL(currentElement);
        currentElement->PL = new double[nh];
        initPL(currentElement);
    }


    SOE soe;
    soe.HG = new double*[nh];
    for (int i = 0; i < nh; i++) {
        soe.HG[i] = new double[nh];
        for (int j = 0; j < nh; j++) {
            soe.HG[i][j] = 0.0;
        }
    }
    soe.PG = new double[nh];
    for (int i = 0; i < nh; i++) {
        soe.PG[i] = 0.0;
    }
    soe.TG = new double[nh];
    for (int i = 0; i < nh; i++) {
        soe.TG[i] = 0.0;
    }

    printHG(soe.HG);


    for (int i = 0; i < (nh - 1); i++) {
        Element* currentElement = &elements[i];

        soe.HG[currentElement->ID[0] - 1][currentElement->ID[0] - 1] += currentElement->HL[0][0];
        soe.HG[currentElement->ID[0] - 1][currentElement->ID[1] - 1] += currentElement->HL[0][1];
        soe.HG[currentElement->ID[1] - 1][currentElement->ID[0] - 1] += currentElement->HL[1][0];
        soe.HG[currentElement->ID[1] - 1][currentElement->ID[1] - 1] += currentElement->HL[1][1];
    }

    printHG(soe.HG);




    return 0;
}