
#include <include/PersegiPanjang.hpp>
#include <iostream>



int main(){
	double TengahX1, TengahY1, TengahX2, TengahY2, Panjang1, Panjang2, Lebar1, Lebar2;
	int pilihan, input;

	std::cout << "------------------------------Operator Overloading------------------------------" << std::endl << std::endl;

	std::cout << "Persegi Panjang 1---------------------------------------------------------------" << std::endl;
	std::cout << "Titik Tengah (X) : " ;
	std::cin  >> TengahX1;
	std::cout << "Titik Tengah (Y) : " ;
	std::cin  >> TengahY1;
	std::cout << "Panjang          : " ;
	std::cin  >> Panjang1;
	std::cout << "Lebar            : " ;
	std::cin  >> Lebar1;
	std::cout << std::endl;
	PersegiPanjang object1 = PersegiPanjang(TengahX1, TengahY1, Panjang1, Lebar1);

        std::cout << "Persegi Panjang 2---------------------------------------------------------------" << std::endl;
        std::cout << "Titik Tengah (X) : " ;
        std::cin  >> TengahX2;
        std::cout << "Titik Tengah (Y) : " ;
        std::cin  >> TengahY2;
        std::cout << "Panjang          : " ;
        std::cin  >> Panjang2;
        std::cout << "Lebar            : " ;
        std::cin  >> Lebar2;
	std::cout << std::endl << std::endl;
	PersegiPanjang object2 = PersegiPanjang(TengahX2, TengahY2, Panjang2, Lebar2);

	std::cout << "Operator----------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "Operator [] = Mengambil masing-masing member dari kelas PersegiPanjang."  << std::endl;
	std::cout << "Operator == = Menentukan ada tidaknya irisan pada kedua object persegi."  << std::endl;
	std::cout << "Operator + = Mengambil luas gabungan kedua object (Harus Beririsan)." << std::endl;
	std::cout << "Operator - = Mengambil irisan dari kedua object persegi." << std::endl;
	std::cout << "Operator ++ = Menambah luasan kelas PersegiPanjang berupa 2 kalinya."  << std::endl;
	std::cout << "Operator -- = Mengurangi luasan kelas PersegiPanjang berupa 1/2 kalinya." << std::endl << std::endl;

	std::cout << "Pilih Object Class : " << std::endl;
	std::cout << "1. Persegi 1 " << std::endl;
	std::cout << "2. Persegi 2 " << std::endl;
	std::cout << "3. Irisan Kedua Persegi"    << std::endl;
	std::cout << "4. Gabungan Kedua Persegi " << std::endl;
	std::cout << "Pilih Nomor " ;
	std::cin  >> pilihan;
	std::cout << std::endl;

	PersegiPanjang irisan = PersegiPanjang(0.00, 0.00, 0.00, 0.00);

	switch(pilihan)
	{
		case 1:
		{
			std::cout << "Persegi 1-----------------------------------------------" << std::endl;

			for(int i = 0; i < 4; i++)
			{
				if(i == 0)
				{
					std::cout << "Xmin : " << object1[i] << std::endl;
				}

                                else if(i == 1)
                                {
                                        std::cout << "Ymin : " << object1[i] << std::endl;
                                }

                                else if(i == 2)
                                {
                                        std::cout << "Xmax : " << object1[i] << std::endl;
                                }

                                else if(i == 3)
                                {
                                        std::cout << "Ymax : " << object1[i] << std::endl;
                                }

			}

			object1.setArea();
			double Luas = object1.getArea();
			std::cout << "Luas : " << Luas << std::endl;

			std::cout << "Increment berapa kali : " ;
			std::cin  >> input;

			for(int j = 0; j < input; j++)
			{
				Luas  = object1++;

                                        for(int k = 0; k < 4; k++)
                                        {
                                                object1 = object1.Increment(object1);

                                                if(k == 0)
                                                {
                                                        std::cout << "Xmin : " << object1[k] << std::endl;
                                                }

                                                else if(k == 1)
                                                {
                                                        std::cout << "Ymin : " << object1[k] << std::endl;
                                                }

                                                else if(k == 2)
                                                {
                                                        std::cout << "Xmax : " << object1[k] << std::endl;
                                                }

                                                else if(k == 3)
                                                {
                                                        std::cout << "Ymax : " << object1[k] << std::endl;
                                                }
                                        }

				std::cout << "Luas Setelah Increment " << j + 1 << "kali : " << Luas << std::endl << std::endl;
			}

                        std::cout << "Decrement berapa kali : " ;
                        std::cin  >> input;

                        for(int l = 0; l < input; l++)
                        {
                                Luas  = object1--;

                                        for(int m = 0; m < 4; m++)
                                        {
                                                object1 = object1.Decrement(object1);

                                                if(m == 0)
                                                {
                                                        std::cout << "Xmin : " << object1[m] << std::endl;
                                                }

                                                else if(m == 1)
                                                {
                                                        std::cout << "Ymin : " << object1[m] << std::endl;
                                                }

                                                else if(m == 2)
                                                {
                                                        std::cout << "Xmax : " << object1[m] << std::endl;
                                                }

                                                else if(m == 3)
                                                {
                                                        std::cout << "Ymax : " << object1[m] << std::endl;
                                                }
                                        }

                                std::cout << "Luas Setelah Decrement " << l + 1 << "kali : " << Luas << std::endl << std::endl;
                        }

			break;
		}

		case 2:
		{
                        std::cout << "Persegi 2-----------------------------------------------" << std::endl;

                        for(int i = 0; i < 4; i++)
                        {
                                if(i == 0)
                                {
                                        std::cout << "Xmin : " << object2[i] << std::endl;
                                }

                                else if(i == 1)
                                {
                                        std::cout << "Ymin : " << object2[i] << std::endl;
                                }

                                else if(i == 2)
                                {
                                        std::cout << "Xmax : " << object2[i] << std::endl;
                                }

                                else if(i == 3)
                                {
                                        std::cout << "Ymax : " << object2[i] << std::endl;
                                }

                        }

			object2.setArea();
                        double Luas = object2.getArea();
                        std::cout << "Luas : " << Luas << std::endl;

                        std::cout << "Increment berapa kali : " ;
                        std::cin  >> input;

                        for(int j = 0; j < input; j++)
                        {
                                Luas  = object2++;

                                        for(int k = 0; k < 4; k++)
                                        {
                                                object2 = object2.Increment(object2);

                                                if(k == 0)
                                                {
                                                        std::cout << "Xmin : " << object2[k] << std::endl;
                                                }

                                                else if(k == 1)
                                                {
                                                        std::cout << "Ymin : " << object2[k] << std::endl;
                                                }

                                                else if(k == 2)
                                                {
                                                        std::cout << "Xmax : " << object2[k] << std::endl;
                                                }

                                                else if(k == 3)
                                                {
                                                        std::cout << "Ymax : " << object2[k] << std::endl;
                                                }
                                        }

                                std::cout << "Luas Setelah Increment " << j + 1 << "kali : " << Luas << std::endl << std::endl;
                        }

                        std::cout << "Decrement berapa kali : " ;
                        std::cin  >> input;

                        for(int l = 0; l < input; l++)
                        {
                                Luas  = object2--;

                                        for(int m = 0; m < 4; m++)
                                        {
                                                object2 = object2.Decrement(object2);

                                                if(m == 0)
                                                {
                                                        std::cout << "Xmin : " << object2[m] << std::endl;
                                                }

                                                else if(m == 1)
                                                {
                                                        std::cout << "Ymin : " << object2[m] << std::endl;
                                                }

                                                else if(m == 2)
                                                {
                                                        std::cout << "Xmax : " << object2[m] << std::endl;
                                                }

                                                else if(m == 3)
                                                {
                                                        std::cout << "Ymax : " << object2[m] << std::endl;
                                                }
                                        }

                                std::cout << "Luas Setelah Decrement " << l + 1 << "kali : " << Luas << std::endl << std::endl;
                        }

                        break;
		}

		case 3:
		{
                        std::cout << "Irisan---------------------------------------------------" << std::endl;

			if(object1 == object2)
			{
				irisan = irisan.irisan(object1);

                        	for(int i = 0; i < 4; i++)
                        	{
                                	if(i == 0)
                                	{
                                        	std::cout << "Xmin : " << irisan[i] << std::endl;
                                	}

                                	else if(i == 1)
                                	{
                                        	std::cout << "Ymin : " << irisan[i] << std::endl;
                                	}

                                	else if(i == 2)
                                	{
                                        	std::cout << "Xmax : " << irisan[i] << std::endl;
                                	}

                                	else if(i == 3)
                                	{
                                        	std::cout << "Ymax : " << irisan[i] << std::endl;
                                	}
				}

				double Area = object1 - object2;

				std::cout << "Luas irisan : " << Area << std::endl;

                       		std::cout << "Increment berapa kali : " ;
                        	std::cin  >> input;

                        	for(int j = 0; j < input; j++)
                        	{
                                	Area = irisan++;

                                        for(int k = 0; k < 4; k++)
                                        {
                                                irisan = irisan.Increment(irisan);

                                                if(k == 0)
                                                {
                                                        std::cout << "Xmin : " << irisan[k] << std::endl;
                                                }

                                                else if(k == 1)
                                                {
                                                        std::cout << "Ymin : " << irisan[k] << std::endl;
                                                }

                                                else if(k == 2)
                                                {
                                                        std::cout << "Xmax : " << irisan[k] << std::endl;
                                                }

                                                else if(k == 3)
                                                {
                                                        std::cout << "Ymax : " << irisan[k] << std::endl;
                                                }
                                        }

                                	std::cout << "Luas Setelah Increment " << j + 1 << "kali : " << Area << std::endl << std::endl;
                        	}

                        	std::cout << "Decrement berapa kali : " ;
                        	std::cin  >> input;

                        	for(int l = 0; l < input; l++)
                        	{
                                	Area = irisan--;

                                        for(int m = 0; m < 4; m++)
                                        {
                                                irisan = irisan.Decrement(irisan);

                                                if(m == 0)
                                                {
                                                        std::cout << "Xmin : " << irisan[m] << std::endl;
                                                }

                                                else if(m == 1)
                                                {
                                                        std::cout << "Ymin : " << irisan[m] << std::endl;
                                                }

                                                else if(m == 2)
                                                {
                                                        std::cout << "Xmax : " << irisan[m] << std::endl;
                                                }

                                                else if(m == 3)
                                                {
                                                        std::cout << "Ymax : " << irisan[m] << std::endl;
                                                }
                                        }

                                	std::cout << "Luas Setelah Decrement " << l + 1 << "kali : " << Area << std::endl << std::endl;
                        	}
			}

			else
			{
				std::cout << "Kedua Persegi Tidak Beririsan." << std::endl;
			}

			break;
		}

		case 4:
		{
			std::cout << "Gabungan------------------------------------------------" << std::endl;

			if(object1 == object2)
			{
                                PersegiPanjang Gabungan = PersegiPanjang(0.00, 0.00, 0.00, 0.00);
                                irisan = irisan.irisan(object1);
                                Gabungan = Gabungan.Gabungan(irisan, object1, object2);

                                for(int i = 0; i < 4; i++)
                                {
                                        if(i == 0)
                                        {
                                                std::cout << "Xmin : " << Gabungan[i] << std::endl;
                                        }

                                        else if(i == 1)
                                        {
                                                std::cout << "Ymin : " << Gabungan[i] << std::endl;
                                        }

                                        else if(i == 2)
                                        {
                                                std::cout << "Xmax : " << Gabungan[i] << std::endl;
                                        }

                                        else if(i == 3)
                                        {
                                                std::cout << "Ymax : " << Gabungan[i] << std::endl;
                                        }
                                }

                                double Area = object1 + object2;

                                std::cout << "Luas gabungan : " << Area << std::endl;

                                std::cout << "Increment berapa kali : " ;
                                std::cin  >> input;

                                for(int j = 0; j < input; j++)
                                {
                                        Area = Gabungan++;

                                	for(int k = 0; k < 4; k++)
                                	{
						Gabungan = Gabungan.Increment(Gabungan);

                                        	if(k == 0)
                                        	{
                                                	std::cout << "Xmin : " << Gabungan[k] << std::endl;
                                        	}

                                        	else if(k == 1)
                                        	{
                                                	std::cout << "Ymin : " << Gabungan[k] << std::endl;
                                        	}

                                        	else if(k == 2)
                                        	{
                                                	std::cout << "Xmax : " << Gabungan[k] << std::endl;
                                        	}

                                        	else if(k == 3)
                                        	{
                                                	std::cout << "Ymax : " << Gabungan[k] << std::endl;
                                        	}
                                	}

                                        std::cout << "Luas Setelah Increment " << j + 1 << "kali : " << Area << std::endl << std::endl;
                                }

                                std::cout << "Decrement berapa kali : " ;
                                std::cin  >> input;

                                for(int l = 0; l < input; l++)
                                {
                                        Area = Gabungan--;

                                        for(int m = 0; m < 4; m++)
                                        {
                                                Gabungan = Gabungan.Decrement(Gabungan);

                                                if(m == 0)
                                                {
                                                        std::cout << "Xmin : " << Gabungan[m] << std::endl;
                                                }

                                                else if(m == 1)
                                                {
                                                        std::cout << "Ymin : " << Gabungan[m] << std::endl;
                                                }

                                                else if(m == 2)
                                                {
                                                        std::cout << "Xmax : " << Gabungan[m] << std::endl;
                                                }

                                                else if(m == 3)
                                                {
                                                        std::cout << "Ymax : " << Gabungan[m] << std::endl;
                                                }
                                        }

                                        std::cout << "Luas Setelah Decrement " << l + 1 << "kali : " << Area << std::endl << std::endl;
                                }
                        }

                        else
                        {
                                std::cout << "Kedua Persegi Tidak Memenuhi Syarat (Harus Beririsan)." << std::endl;
                        }

                        break;
		}
	}
	return 0;
}


