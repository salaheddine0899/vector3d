#include "pch.h"
#include "Matrice.h"
#include <assert.h>
namespace LA {
	Matrice::Matrice(int l, int c)
	{
		this->col = c;
		this->ligne = l;
		this->mat = new int*[l];
		for(int i=0;i<l;i++)
			this->mat[i] = new int[c];
		for (int i = 0; i < l; i++)
			for (int j = 0; j < c; j++)
				this->mat[i][j] = 0;
	}
	void Matrice::Remplissage(int x)
	{
		for (int i = 0; i < this->ligne; i++)
			for (int j = 0; j < this->col; j++)
				this->mat[i][j] = x;
	}
	Matrice& Matrice::operator+(const Matrice& m)
	{
		// TODO: insert return statement here
		assert(this->ligne == m.ligne && this->col == m.col);
		try {
			if (this->ligne != m.ligne || this->col != m.col) throw "ils n'ont pas la meme taille";
			Matrice* res = new Matrice(this->ligne, this->col);
			for (int i = 0; i < this->ligne; i++)
				for (int j = 0; j < this->col; j++)
					res->mat[i][j] = this->mat[i][j] + m.mat[i][j];
			return *res;
		}
		catch (string exep) {
			cout << exep << endl;
		}
	}
	Matrice& Matrice::operator-(const Matrice& m)
	{
		// TODO: insert return statement here
		assert(this->ligne == m.ligne && this->col == m.col);
		try {
			if (this->ligne != m.ligne || this->col != m.col) throw "ils n'ont pas la meme taille";
			Matrice* res = new Matrice(this->ligne, this->col);
			for (int i = 0; i < this->ligne; i++)
				for (int j = 0; j < this->col; j++)
					res->mat[i][j] = this->mat[i][j] - m.mat[i][j];
			return *res;
		}
		catch (string exep) {
			cout << exep << endl;
		}
	}
	Matrice& Matrice::operator*(const Matrice& m)
	{
		// TODO: insert return statement here
		assert(this->col==m.ligne);
		try
		{
			if (this->col != m.ligne) throw "impossible de faire le produit";
			Matrice* res = new Matrice(this->ligne, m.col);
			int somme;
			for (int i = 0; i < this->ligne; i++) {
				for (int j = 0; j < m.col; j++) {
					somme = 0;
					for (int k = 0; k < this->col; k++)	somme += this->mat[i][k] * m.mat[k][j];
					res->mat[i][j] = somme;
				}
			}
			return *res;
		}
		catch (string exception)
		{
			cout << exception << endl;
		}
	}
	Matrice& Matrice::operator*(const int& m)
	{
		// TODO: insert return statement here
		Matrice* res = new Matrice(this->ligne, this->col);
		for (int i = 0; i < this->ligne; i++)
			for (int j = 0; j < this->col; j++)
				res->mat[i][j] = m * this->mat[i][j];

		return *res;
	}
	Matrice::~Matrice()
	{
		for (int i = 0; i < this->ligne; i++) {
			delete[] this->mat[i];
			this->mat[i] = nullptr;

		}
		delete[] this->mat;
		this->mat = nullptr; 
	}
	void Matrice::print() const
	{
		cout << "----------La matrice------------" << endl;
		for (int i = 0; i < this->ligne; i++) {
			for (int j = 0; j < this->col; j++)
				cout << this->mat[i][j] << '\t';
			cout << endl;
		}
	}
}
