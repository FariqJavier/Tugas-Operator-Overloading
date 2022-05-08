
#include <include/PersegiPanjang.hpp>
#include <iostream>


        PersegiPanjang::PersegiPanjang(double xmid, double ymid, double length, double width)
        {
		this->x1 = 0.00;
		this->y1 = 0.00;
		this->x2 = 0.00;
		this->y2 = 0.00;
		this->Area = 0.00;

                this->xmin = xmid - (length/2);
                this->xmax = xmid + (length/2);
                this->ymin = ymid - (width/2);
                this->ymax = ymid + (width/2);
        }

        void PersegiPanjang::setAttribute(double xmin, double ymin, double xmax, double ymax)
        {
                this->xmin = xmin;
                this->ymin = ymin;
                this->xmax = xmax;
                this->ymax = ymax;
        }

	void PersegiPanjang::setArea()
	{
		this->Area = (this->xmax - this->xmin) * (this->ymax - this->ymin);
	}

        double PersegiPanjang::getArea()
        {
                return this->Area;
        }

        bool PersegiPanjang::operator == (const PersegiPanjang& persegi)
        {
		bool temp = false;
                if(this->xmin >= persegi.xmin && this->xmin < persegi.xmax)
                {
                        this->x1 = this->xmin;
                        this->x2 = persegi.xmax;

                        if(this->ymin >= persegi.ymin && this->ymin < persegi.ymax)
                        {
                                this->y1 = this->ymin;
                                this->y2 = persegi.ymax;

                                temp = true;
                        }

                        else if(this->ymax >= persegi.ymin && this->ymax < persegi.ymax)
                        {
                                this->y2 = this->ymax;
                                this->y1 = persegi.ymin;

                                temp = true;
                        }
                }

                else if(this->xmax >= persegi.xmin && this->xmax < persegi.xmax)
                {
                        this->x2 = this->xmax;
                        this->x1 = persegi.xmin;

                        if(this->ymin >= persegi.ymin && this->ymin < persegi.ymax)
                        {
                                this->y1 = this->ymin;
                                this->y2 = persegi.ymax;

                                temp = true;
                        }

                        else if(this->ymax >= persegi.ymin && this->ymax < persegi.ymax)
                        {
                                this->y2 = this->ymax;
                                this->y1 = persegi.ymin;

                                temp = true;
                        }
                }

		else
		{
                	temp = false;
		}

		return temp;
        }

        double PersegiPanjang::operator [] (int index)
        {
                int n = index % 4;

                if(n == 0)
                {
                        return this->xmin;
                }

                else if(n == 1)
                {
                        return this->ymin;
                }

                else if(n == 2)
                {
                        return this->xmax;
                }

                else if(n == 3)
                {
                        return this->ymax;
                }

		else
		{
                	return 0.00;
		}
        }

        double PersegiPanjang::operator + (const PersegiPanjang& persegi)
        {
		double total = 0.00;

                if(this->x1 == 0.00)
                {
                        if(this->x2 == 0.00)
                        {
				this->y1 = persegi.y1;
				this->y2 = persegi.y2;

                                total = 0.00;
                        }
                }

                else if(this->y1 == 0.00)
                {
                        if(this->y2 == 0.00)
                        {
				this->x1 = persegi.x1;
				this->x2 = persegi.x2;

                                total = 0.00;
                        }
                }

		else
		{
                	PersegiPanjang temp = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                	temp.setAttribute(persegi.xmin, persegi.ymin, persegi.xmax, persegi.ymax);
			this->setArea();
			temp.setArea();
                	total = this->Area + temp.Area;
		}

		return total;
        }

        double PersegiPanjang::operator - (const PersegiPanjang& Persegi)
        {
		double total = 0.00;

                if((this->x1 = 0.00))
                {
                        if((this->x2 = 0.00))
                        {
				this->y1 = Persegi.y1;
				this->y2 = Persegi.y2;

                                total = 0.00;
                        }
                }

                else if((this->y1 = 0.00))
                {
                        if((this->y2 = 0.00))
                        {
				this->x1 = Persegi.x1;
				this->x2 = Persegi.x2;

                                total = 0.00;
                        }
                }

		else
		{
                	total = (this->x2 - this->x1) * (this->y2 - this->y1);
		}

		return total;
        }

        double PersegiPanjang::operator ++ (int)
    	{
		this->setArea();
		this->Area = this->Area * 2.00;

                return this->Area;
        }

        double PersegiPanjang::operator -- (int)
        {
                this->setArea();
                this->Area = this->Area / 2.00;

                return this->Area;
        }

        PersegiPanjang PersegiPanjang::Gabungan(const PersegiPanjang& irisan, const PersegiPanjang& persegi1, const PersegiPanjang& persegi2)
        {
                PersegiPanjang persegi = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                persegi.xmin = ((irisan.xmin + irisan.xmax) / 2) - ((persegi1.xmin + persegi1.xmax + persegi2.xmin + persegi2.xmax) / 2);
                persegi.ymin = ((irisan.ymin + irisan.ymax) / 2) - ((persegi1.ymin + persegi1.ymax + persegi2.ymin + persegi2.ymax) / 2);
                persegi.xmax = ((irisan.xmin + irisan.xmax) / 2) + ((persegi1.xmin + persegi1.xmax + persegi2.xmin + persegi2.xmax) / 2);
                persegi.ymax = ((irisan.ymin + irisan.ymax) / 2) + ((persegi1.ymin + persegi1.ymax + persegi2.ymin + persegi2.ymax) / 2);

                return persegi;
        }

        PersegiPanjang PersegiPanjang::irisan(const PersegiPanjang& persegi)
        {
                PersegiPanjang beririsan = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                beririsan.xmin = persegi.x1;
                beririsan.ymin = persegi.y1;
                beririsan.xmax = persegi.x2;
                beririsan.ymax = persegi.y2;

                return beririsan;
        }

        PersegiPanjang PersegiPanjang::Increment(const PersegiPanjang& Gabungan)
        {
                PersegiPanjang persegi = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                if((Gabungan.xmax - Gabungan.xmin) > (Gabungan.ymax - Gabungan.ymin))
                {
                        persegi.xmin = Gabungan.xmin - ((Gabungan.xmax + Gabungan.xmin) / 2);
                        persegi.xmax = Gabungan.xmax + ((Gabungan.xmax + Gabungan.xmin) / 2);
                        persegi.ymin = Gabungan.ymin;
                        persegi.ymax = Gabungan.ymax;

                        return persegi;
                }

                else
                {
                        persegi.xmin = Gabungan.xmin;
                        persegi.xmax = Gabungan.xmax;
                        persegi.ymin = Gabungan.ymin - ((Gabungan.xmax + Gabungan.xmin) / 2);
                        persegi.ymax = Gabungan.ymax + ((Gabungan.xmax + Gabungan.xmin) / 2);

                        return persegi;

                }
        }

        PersegiPanjang PersegiPanjang::Decrement(const PersegiPanjang& irisan)
        {
                PersegiPanjang persegi = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                if((irisan.xmax - irisan.xmin) > (irisan.ymax - irisan.ymin))
                {
                        persegi.xmin = irisan.xmin + ((irisan.xmax + irisan.xmin) / 2);
                        persegi.xmax = irisan.xmax - ((irisan.xmax + irisan.xmin) / 2);
                        persegi.ymin = irisan.ymin;
                        persegi.ymax = irisan.ymax;

                        return persegi;
                }

                else
                {
                        persegi.xmin = irisan.xmin;
                        persegi.xmax = irisan.xmax;
                        persegi.ymin = irisan.ymin + ((irisan.xmax + irisan.xmin) / 2);
                        persegi.ymax = irisan.ymax - ((irisan.xmax + irisan.xmin) / 2);

                        return persegi;

                }
        }




