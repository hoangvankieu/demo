using System;

namespace Vòng_lặp
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] X;
            X = new double[14];
            Random rand = new Random();
            double Coin_Error = rand.NextDouble() % 10 + 1;
            double Coin_real = rand.NextDouble() % 10 + 1.11;
            int Ps_Error = rand.Next() % 13 + 1;
            for (int i = 1; i < 14; ++i)
            {
                if (i == Ps_Error)
                {
                    X[i] = Coin_Error;
                }
                else
                {
                    X[i] = Coin_real;
                }
            }
            double A, B;
            //Lần 1;
            A = X[1] + X[2] + X[3] + X[4];
            B = X[5] + X[6] + X[7] + X[8];
            if (A == B)
            {//A = B=> C lỗi
             //Lần 2
                double V1, V2;
                V1 = X[1] + X[9];//Cần 1,9 với 10,11
                V2 = X[10] + X[11];
                if (V1 == V2)
                {//V1=V2 => 12,13 lỗi
                    if (X[1] == X[12])
                    {
                        Console.WriteLine("The coin number 13 error {0:0.00}", X[13]);
                    }
                    else
                    {
                        Console.WriteLine("The coin number 12 error {0:0.00}", X[12]);
                    }
                }
                else
                {
                    double L1, L2;
                    L1 = X[1] + X[2];
                    L2 = X[9] + X[10];
                    if (L1 == L2)
                    {
                        Console.WriteLine("The coin number 11 error {0:0.00}", X[11]);
                    }
                    else
                    {
                        if (L1 > L2)
                        {
                            if (V1 > V2)
                            {
                                Console.WriteLine("The coin number 10 error {0:0.00}", X[10]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 9 error {0:0.00}", X[9]);
                            }
                        }
                        else
                        {
                            if (V1 > V2)
                            {
                                Console.WriteLine("The coin number 9 error {0:0.00}", X[9]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 10 error {0:0.00}", X[10]);
                            }
                        }
                    }
                }
            }
            else
            {
                double V1, V2;
                V1 = X[1] + X[2] + X[6];
                V2 = X[3] + X[5] + X[9];
                if (V1 == V2)
                {//4,7,8 lỗi;
                    if (X[7] == X[8])
                    {
                        Console.WriteLine("The coin number 4 error {0:0.00}", X[4]);
                    }
                    else
                    {
                        if (B < A)
                        {
                            if (X[7] > X[8])
                            {
                                Console.WriteLine("The coin number 8 error {0:0.00}", X[8]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 7 error {0:0.00}", X[7]);
                            }
                        }
                        else
                        {
                            if (X[7] > X[8])
                            {
                                Console.WriteLine("The coin number 7 error {0:0.00}", X[7]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 8 error {0:0.00}", X[8]);
                            }
                        }
                    }
                }
                else if (A > B && V1 < V2 || A < B && V1 > V2)
                {//3||6 lỗi
                    if (X[1] == X[6])
                    {
                        Console.WriteLine("The coin number 3 error {0:0.00}", X[3]);
                    }
                    else
                    {
                        Console.WriteLine("The coin number 6 error {0:0.00}", X[6]);
                    }
                }
                else
                {// 1,2,5 lỗi
                    double L1, L2;
                    L1 = X[1] + X[5];
                    L2 = X[9] + X[10];
                    if (L1 == L2)
                    {
                        Console.WriteLine("The coin number 2 error {0:0.00}", X[2]);
                    }
                    else
                    {
                        if (L1 > L2)
                        {
                            if (V1 > V2)
                            {
                                Console.WriteLine("The coin number 1 error {0:0.00}", X[1]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 5 error {0:0.00}", X[5]);
                            }
                        }
                        else
                        {
                            if (V1 > V2)
                            {
                                Console.WriteLine("The coin number 5 error {0:0.00}", X[5]);
                            }
                            else
                            {
                                Console.WriteLine("The coin number 1 error {0:0.00}", X[1]);
                            }
                        }
                    }
                }
            }
            for (int i = 1; i < 14; ++i)
            {
                Console.Write("Coin {0}: {1:0.00 }\n",i, X[i]);
            }
        }
    }
	
}
