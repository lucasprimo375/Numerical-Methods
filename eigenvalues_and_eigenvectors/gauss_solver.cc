#include <tuple>

#include "gauss_solver.h"
#include "vector.h"
#include "matrix.h"

Vector* GaussSolver::solve( Matrix* A, Vector* b ) {
	std::tuple<Matrix*, Vector*>* Bc = GaussSolver::gaussElimination( A, b );

	Matrix* B;
	Vector* c;

	std::tie(B, c) = *Bc;

	return GaussSolver::solveSuperiorTriangular( B, c );
}

std::tuple<Matrix*, Vector*>* GaussSolver::gaussElimination( Matrix* A, Vector* b ) {
	Matrix* B = A->copy();
	Vector* c = b->copy();

	for( int k = 0; k < B->getSize() - 1; k++ ) {
		for( int i = k + 1; i < B->getSize(); i++ ){
			double m = -B->getElement(i, k)/B->getElement(k, k);

			B->addElement(i, k, 0);

			for(int j = k + 1; j < B->getSize(); j++)
				B->addElement(i, j, B->getElement(i, j) + m*B->getElement(k, j));

			c->addElement(i, c->getElement(i) + m*c->getElement(k));
		}
	}

	std::tuple<Matrix*, Vector*>* Bc = new std::tuple<Matrix*, Vector*>(B, c);

	return Bc;
}

Vector* GaussSolver::solveSuperiorTriangular( Matrix* A, Vector* b ) {
    Vector* x = new Vector( b->getSize() );
    x->addElement( x->getSize() - 1, b->getElement(b->getSize()-1)/A->getElement(A->getSize()-1, A->getSize()-1) );

    for( int k = A->getSize() - 2; k > -1; k-- ){
    	double sum = 0;

    	for( int j = k + 1; j < A->getSize(); j++ )
    		sum += A->getElement(k, j)*x->getElement(j);

    	x->addElement(k, (b->getElement(k) - sum)/A->getElement(k, k));
    }

    return x;
}