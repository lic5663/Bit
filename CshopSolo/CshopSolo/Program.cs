using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class CalculatorAnother
    {
        public static int Plus(int a, int b)
        {
            WriteLine($"Input : {a} , {b}");
            int result = a + b;
            return result;
        }
    }
}

namespace CshopSolo
{
    class Calculator
    {
        public static int Plus(int a, int b)
        {
            WriteLine($"Input : {a} , {b}");
            int result = a + b;
            return result;
        }

        public static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public static void Divide (int a, int b, out int quotient, out int remainder)
        {
            quotient = a / b;
            remainder = a % b;
        }

        public int Sum (params int[] args)
        {
            int sum = 0;
            for(int i = 0; i< args.Length; i++)
            {
                sum += args[i];
            }
            return sum;
        }

        public void PrintProfile(string name, string phone)
        {
            WriteLine($"Name : {name} , Phone : {phone}");
        }

    }


    class Product
    {
        private int price = 100;

        public ref int GetPrice()
        {
            return ref price;
        }

        public void PrintPrice()
        {
            WriteLine($"Price : {price}");
        }
    }

    class Program
    {
        static void ch5()
        {
            int[] arr = new int[] { 0, 1, 2, 3, 4 };
            int[] brr = { 1, 2, 3, 4, 5, 6 };

            foreach(int a in arr)
            {
                WriteLine(a);
            }

            foreach(int a in brr)
            {
                WriteLine(a);
            }

            for (int i= 0; i<5;i++)
            {
                for (int j = 0; j <= i; j++)
                    Write('*');
                WriteLine();
            }

            WriteLine();

            for (int i=0; i<5; i++)
            {
                for (int j = 5; j >i; j--)
                    Write('*');
                WriteLine();
            }

            int n = 0;
            int m = 0;
            while (n < 5)
            {
                while (m <= n)
                {
                    Write('*');
                    m++;
                }
                    
                WriteLine();
                m = 0;
                n++;
            }

        }

        static void ch6()
        {
            int x = Calculator.Plus(3, 4);
            int y = Calculator.Plus(5, 6);
            int z = test.CalculatorAnother.Plus(7, 6);
            WriteLine(x);
            WriteLine(y);
            WriteLine(z);
            WriteLine($"{x} , {y}");
            Calculator.Swap(ref x, ref y);
            WriteLine($"{x} , {y}");

            Product carrot = new Product();
            ref int ref_local_price = ref carrot.GetPrice();
            int normal_local_price = carrot.GetPrice();

            carrot.PrintPrice();
            WriteLine($"Ref Local Price : {ref_local_price}");
            WriteLine($"Normal Local Price : {normal_local_price}");

            ref_local_price = 200;

            carrot.PrintPrice();
            WriteLine($"Ref Local Price : {ref_local_price}");
            WriteLine($"Normal Local Price : {normal_local_price}");

            int a = 20;
            int b = 3;
            int q;
            int r;

            Calculator.Divide(a, b, out q, out r);
            WriteLine($"{a} {b} {q} {r}");
            Calculator cal = new Calculator();
            int sum = cal.Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
            WriteLine($"{sum}");
            cal.PrintProfile(phone: "모름", name: "이인찬");
            
        }

        static void Main(string[] args)
        {
            //ch5();
            ch6();
        }
    }
}
