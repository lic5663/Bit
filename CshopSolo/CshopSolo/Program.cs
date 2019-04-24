using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

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

        public static void Divide(int a, int b, out int quotient, out int remainder)
        {
            quotient = a / b;
            remainder = a % b;
        }

        public int Sum(params int[] args)
        {
            int sum = 0;
            for (int i = 0; i < args.Length; i++)
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

    class Cat
    {

        public string Name;
        public string Color;

        public Cat(string name = "나비", string color = "신비로운색")
        {
            Name = name;
            Color = color;
        }
        ~Cat()
        {
            WriteLine($"{Name} : 바이바이");
        }

        public void Meow()
        {
            WriteLine($"{Name} : 야옹");
        }

    }

    class TmpClass
    {
        public int MyField1;
        public int MyField2;

        public TmpClass DeepCopy()
        {
            TmpClass newCopy = new TmpClass();
            newCopy.MyField1 = this.MyField1;
            newCopy.MyField2 = this.MyField2;

            return newCopy;
        }
    }

    class ThisClass
    {
        int a, b, c;

        public ThisClass()
        {
            this.a = 5425;
        }

        public ThisClass(int b) : this()
        {
            this.b = b;
        }

        public ThisClass(int b, int c) : this(b)
        {
            this.c = c;
        }

        public void PrintField()
        {
            WriteLine($"a:{a}, b:{b}, c:{c}");
        }
    }

    class Mammal
    {
        public void Nurse()
        {
            WriteLine("Nurse()");
        }
    }

    class Dog : Mammal
    {
        public void Bark()
        {
            WriteLine("Bark()");
        }
    }

    class CCat : Mammal
    {
        public void Meow()
        {
            WriteLine("Meow()");
        }
    }

    class ArmorSuite
    {
        public virtual void Initialize()
        {
            WriteLine("Armored");
        }
    }

    class IronMan : ArmorSuite
    {
        public override void Initialize()
        {
            base.Initialize();
            WriteLine("Repulsor Rays Armed");
        }
    }

    class WarMachine : ArmorSuite
    {
        public override void Initialize()
        {
            base.Initialize();
            WriteLine("Double-Barrel Cannons Armed");
            WriteLine("Micro-Rocket Launcher Armed");
        }
    }

    class Base
    {
        public void MyMethod()
        {
            WriteLine("Base.MyMethod");
        }
    }

    class Derived : Base
    {
        public new void MyMethod()
        {
            WriteLine("Derived.MyMethod");
        }
    }

    class OuterClass
    {
        private int OuterMember;

        public class NestedClass
        {
            public void DoSomething()
            {
                OuterClass outer = new OuterClass();
                outer.OuterMember = 10;
            }
        }
    }

    class Configuration
    {
        List<ItemValue> listConfig = new List<ItemValue>();

        public void SetConfig(string item, string value)
        {
            ItemValue iv = new ItemValue();
            iv.SetValue(this, item, value);
        }

        public string GetConfig(string item)
        {
            foreach (ItemValue iv in listConfig)
            {
                if (iv.GetItem() == item)
                    return iv.GetValue();
            }
            return "";
        }
        

        public class ItemValue
        {
            private string item;
            private string value;

            public void SetValue(Configuration config, string item, string value)
            {
                this.item = item;
                this.value = value;

                bool found = false;
                for (int i = 0; i < config.listConfig.Count; i++)
                {
                    if (config.listConfig[i].item == item)
                    {
                        config.listConfig[i] = this;
                        found = true;
                        break;
                    }
                }

                if (found == false)
                    config.listConfig.Add(this);

            }
            public string GetItem()
            {
                return item;
            }
            public string GetValue()
            {
                return value;
            }
        }
    }

    public static class IntegerExtension
    {
        public static int Square (this int myInt)
        {
            return myInt * myInt;
        }

        public static int Power (this int myInt, int exponent)
        {
            int result = myInt;
            for (int i = 1; i < exponent; i++)
                result *= myInt;
            return result;
        }
    }

    public static class StringExtension
    {
        public static string Append(this string mystr, string addstr)
        {
            string apStr = mystr;
            apStr += addstr;
            return apStr;
        }
    }

    interface ILogger
    {
        void WriteLog(string log);
    }
    
    class ConsoleLogger : ILogger
    {
        public void WriteLog(string message)
        {
            WriteLine($"{DateTime.Now.ToLocalTime()} {message}");
        }
    }

    class ClimateMonitor
    {
        private ILogger logger;
        public ClimateMonitor(ILogger logger)
        {
            this.logger = logger;
        }

        public void start()
        {
            while (true)
            {
                Console.Write("온도를 입력하시오 : ");
                string temperature = ReadLine();
                if (temperature == "")
                    break;
                logger.WriteLog("현재 온도 : " + temperature);
            }
        }
    }

    class FileLogger : ILogger
    {
        private StreamWriter writer;

        public FileLogger(string path)
        {
            writer = File.CreateText(path);
            writer.AutoFlush = true;
        }

        public void WriteLog(string message)
        {
            writer.WriteLine($"{DateTime.Now.ToShortDateString()} {message}");
        }
    }

    interface IFormattableLogger : ILogger
    {
        void WriteLog(string format, params Object[] args);
    }

    class ConsoleLogger2 : IFormattableLogger
    {
        public void WriteLog(string message)
        {
            WriteLine($"{DateTime.Now.ToLocalTime()} {message}");
        }

        public void WriteLog(string format, params Object[] args)
        {
            String message = String.Format(format, args);
            Console.WriteLine($"{DateTime.Now.ToLocalTime()} {message}");
        }
    }

    interface IRunnable
    {
        void Run();
    }

    interface IFlyable
    {
        void Run();
        void Fly();
    }

    class FlyingCar : IRunnable,IFlyable
    {
        public void Run()
        {
            WriteLine("RRRRRRun!");
        }

        public void Fly()
        {
            WriteLine("FFFFFFFFFly");
        }
    }

    abstract class AbstractBase
    {
        protected void PrivateMethodA()
        {
            WriteLine("AbstractBase.PrivateMethodA()");
        }

        public void PublicMethodA()
        {
            WriteLine("AbstractBase.PublicMethodA()");
        }

        public abstract void AbstractMethodA();
    }

    class Derived2 : AbstractBase
    {
        public override void AbstractMethodA()
        {
            WriteLine("Derived.AbstractMethodA()");
            PrivateMethodA();
        }
    }


    class Program
    {
        static void ch5()
        {
            int[] arr = new int[] { 0, 1, 2, 3, 4 };
            int[] brr = { 1, 2, 3, 4, 5, 6 };

            foreach (int a in arr)
            {
                WriteLine(a);
            }

            foreach (int a in brr)
            {
                WriteLine(a);
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j <= i; j++)
                    Write('*');
                WriteLine();
            }

            WriteLine();

            for (int i = 0; i < 5; i++)
            {
                for (int j = 5; j > i; j--)
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

        static void ch7()
        {
            Cat kitty = new Cat();
            kitty.Color = "하얀색";
            kitty.Name = "키티";
            kitty.Meow();
            WriteLine($"{kitty.Name} : {kitty.Color}");

            Cat nero = new Cat();
            nero.Color = "검은색";
            nero.Name = "네로";
            nero.Meow();
            WriteLine($"{nero.Name} : {nero.Color}");

            Cat nabi = new Cat();
            nabi.Meow();
            WriteLine($"{nabi.Name} : {nabi.Color}");

            TmpClass source = new TmpClass();
            source.MyField1 = 10;
            source.MyField2 = 20;

            TmpClass copy = source.DeepCopy();
            copy.MyField2 = 30;

            WriteLine($"{source.MyField1} , {source.MyField2}");
            WriteLine($"{copy.MyField1} , {copy.MyField2}");

            ThisClass a = new ThisClass();
            ThisClass b = new ThisClass(1);
            ThisClass c = new ThisClass(10, 20);

            a.PrintField();
            b.PrintField();
            c.PrintField();

            Mammal mammal = new Dog();
            Dog dog;

            if (mammal is Dog)
            {
                dog = (Dog)mammal;
                dog.Bark();
            }

            Mammal mammal2 = new CCat();
            CCat cat = mammal2 as CCat;
            if (cat != null)
            {
                cat.Meow();
            }

            CCat cat2 = mammal as CCat;
            if (cat2 != null)
            {
                cat2.Meow();
            }
            else
                WriteLine("cat2 is not a cat");

            WriteLine("\nCreating ArmorSuite...");
            ArmorSuite armorSuite = new ArmorSuite();
            armorSuite.Initialize();

            WriteLine("\nCreating IronMan...");
            IronMan ironMan = new IronMan();
            ironMan.Initialize();

            WriteLine("\nCreating WarMachine");
            ArmorSuite warmachine = new WarMachine();
            warmachine.Initialize();

            Base baseObj = new Base();
            baseObj.MyMethod();

            Derived derivedObj = new Derived();
            derivedObj.MyMethod();

            Base derivedObj2 = new Derived();
            derivedObj2.MyMethod();


            Configuration config = new Configuration();
            config.SetConfig("Version", "V 5.0");
            config.SetConfig("Size", "655,324 KB");

            WriteLine(config.GetConfig("Version"));
            WriteLine(config.GetConfig("Size"));

            config.SetConfig("Version", "V 5.0.1");
            WriteLine(config.GetConfig("Version"));

            Configuration.ItemValue item = new Configuration.ItemValue();

            WriteLine($"3^2 : {3.Square()}");
            WriteLine($"3^4 : {3.Power(4)}");
            WriteLine($"2^10 : {2.Power(10)}");

            string hello = "Hello";
            WriteLine(hello.Append(", World!"));
        }

        // 인터페이스와 추상 클래스
        static void ch8()
        {
            ConsoleLogger consoleLogger = new ConsoleLogger();
            consoleLogger.WriteLog("하이");

            //ClimateMonitor monitor = new ClimateMonitor(new ConsoleLogger());
            //monitor.start();

            //ClimateMonitor monitor2 = new ClimateMonitor(new FileLogger("MyLog.txt"));
            //monitor2.start();

            IFormattableLogger logger = new ConsoleLogger2();
            logger.WriteLog("The World is not flat.");
            logger.WriteLog($"{1} + {1} = {2}");

            FlyingCar car = new FlyingCar();
            car.Run();
            car.Fly();

            IRunnable runnable = car as IRunnable;
            runnable.Run();

            IFlyable flyable = car as IFlyable;
            flyable.Fly();


            AbstractBase obj = new Derived2();
            obj.AbstractMethodA();
            obj.PublicMethodA();
        }

        static void Main(string[] args)
        {
            //ch5();
            //ch6();
            //ch7();
            ch8();

        }
    }
}
