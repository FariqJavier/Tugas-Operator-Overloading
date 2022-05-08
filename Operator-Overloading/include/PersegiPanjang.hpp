#ifndef __PERSEGIPANJANG_HPP__
#define __PERSEGIPANJANG_HPP__


#include <iostream>

class PersegiPanjang
{
        private:
        double xmin, ymin, xmax, ymax;
        double x1, x2, y1, y2, Area;

        public:
        PersegiPanjang(double xmid, double ymid, double length, double width);

        void setAttribute(double xmin, double ymin, double xmax, double ymax);

	void setArea();

        double getArea();

        bool operator == (const PersegiPanjang& persegi);

        double operator [] (int index);

        double operator + (const PersegiPanjang& persegi);

        double operator - (const PersegiPanjang& Persegi);

        double operator ++ (int);

        double operator -- (int);

        PersegiPanjang Gabungan(const PersegiPanjang& irisan, const PersegiPanjang& persegi1, const PersegiPanjang& persegi2);

        PersegiPanjang irisan(const PersegiPanjang& persegi);

        PersegiPanjang Increment(const PersegiPanjang& Gabungan);

        PersegiPanjang Decrement(const PersegiPanjang& irisan);
};

#endif

