using System;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Collections;

namespace day14
{
    class HelloWorld
    {
        static void ch3()
        {
            WriteLine("여러분, 안녕하세요?");
            WriteLine("반갑습니다!");


            //-------------------------------------------
            sbyte a = -100;
            byte b = 40;

            WriteLine($"a={a}, b ={b}");

            short c = -30000;
            ushort d = 60000;

            WriteLine($"c={c}, d ={d}");

            int e = -1000_0000;
            uint f = 3_0000_0000;

            WriteLine($"e={e}, f ={f}");

            long g = -5000_0000_0000;
            ulong h = 200_0000_0000_0000_0000;

            WriteLine($"g={g}, h ={h}");

            //--------------------------------------------
            byte ab = 240;
            WriteLine($"ab= {ab}");
            WriteLine("ab= {ab}");

            byte bb = 0b1111_0000; // 2진수 리터널
            WriteLine($"bb = {bb}");

            byte cb = 0xF0;
            WriteLine($"cb = {cb}");

            uint db = 0x1234_abcd;
            WriteLine($"db = {db}");

            //---------------------------------------------
            byte ac = 255;
            sbyte bc = (sbyte)ac;

            WriteLine(ac);
            WriteLine(bc);

            //---------------------------------------------
            uint ad = uint.MaxValue;
            WriteLine(ad);
            ad++;
            WriteLine(ad);

            int bd = int.MaxValue;
            WriteLine(bd);
            bd++;
            WriteLine(bd);

            //---------------------------------------------
            float ae = 3.14159265358979323846f;
            WriteLine(ae);
            double be = 3.14159265358979323846;
            WriteLine(be);
            decimal ce = 3.141592653589793238462643383279m;
            WriteLine(ce);
            //---------------------------------------------

            char char_a = '안';
            char char_b = '녕';
            Write(char_a);
            Write(char_b);
            WriteLine();

            string str = "안녀어어어어어어어엉";
            WriteLine(str);

            //---------------------------------------------
            object ob1 = 123;
            object ob2 = "으아아아아아아";
            object ob3 = true;
            object ob4 = 3.14848498454649846844984849849m;
            WriteLine(ob1);
            WriteLine(ob2);
            WriteLine(ob3);
            WriteLine(ob4);

            //---------------------------------------------

            object ob5 = ob4;
            decimal de = (decimal)ob5;
            WriteLine(de);
            //---------------------------------------------

            int temp_int = 123;
            string temp_str = temp_int.ToString();
            WriteLine(temp_str);

            string temp_str2 = "123456";
            int temp_int2 = int.Parse(temp_str2);
            int temp_int3 = Convert.ToInt32(temp_str2);
            WriteLine(temp_int2);
            WriteLine(temp_int3);

            int? a_null = null;
            WriteLine(a_null.HasValue);
            a_null = 37;
            WriteLine(a_null.HasValue);
            WriteLine(a_null.Value);

            //----------------------------------------------

            WriteLine("사각형 너비 입력");
            string width = ReadLine();

            WriteLine("사각형 높이 입력");
            string height = ReadLine();

            int area = int.Parse(width) * int.Parse(height);
            WriteLine($"사각형 넓이 : {area}");

            int area2 = Convert.ToInt32(width) * Convert.ToInt32(height);
            WriteLine($"사각형 넓이 : {area2}");
        }

        static void appendix()
        {
            string greeting = "Good Morning";

            WriteLine(greeting);
            WriteLine();

            WriteLine("IndexOf 'Good' : {0}", greeting.IndexOf("Good"));
            WriteLine("IndexOf 'o' : {0}", greeting.IndexOf('o'));

            WriteLine("LastIndexOf 'Good' : {0}", greeting.LastIndexOf("Good"));
            WriteLine("LastIndexOf 'Morning' : {0}", greeting.LastIndexOf("Morning"));
            WriteLine("LastIndexOf 'o; : {0}", greeting.LastIndexOf('o'));

            WriteLine("StartsWith 'Good' : {0}", greeting.StartsWith("Good"));
            WriteLine("StartWith 'Morning' : {0}", greeting.StartsWith("Morning"));

            WriteLine("EndWith 'Good' : {0}", greeting.EndsWith("Good"));
            WriteLine("EndWith 'Morning' : {0}", greeting.EndsWith("Morning"));

            WriteLine("Contains 'Evening' : {0}'", greeting.Contains("Evening"));
            WriteLine("Contains 'Morning' : {0}'", greeting.Contains("Morning"));

            WriteLine("Replaced 'Morning' with 'Evening' : {0}", greeting.Replace("Morning", "Evening"));

            //-------------------------------------

            greeting = "Good Morning";

            WriteLine(greeting.Substring(0, 5));
            WriteLine(greeting.Substring(5));
            WriteLine();

            //string[] arr = greeting.Split(new string[] { " " }, StringSplitOptions.None);
            string[] arr = greeting.Split(' ');
            WriteLine("Word Count : {0}", arr.Length);

            foreach (string element in arr)
                WriteLine("{0}", element);

            string result = string.Format("{1,-10}{0,10}DEF", "ABC", "XYZ");
            WriteLine(result);

            string fmt = "{0,-20}{1,-15}{2,30}";
            WriteLine(fmt, "Publisher", "Author", "Title");
            WriteLine(fmt, "Marvel", "Stan Lee", "Iron Man");
            WriteLine("{0:N0}", 123456789);

            DateTime dt = new DateTime(2018, 11, 3, 23, 18, 22);
            WriteLine("{0}", dt);
            WriteLine("12시간 형식 : {0:yyyy-MM-dd tt hh:mm:ss (ddd)}", dt);
            WriteLine("24시간 형식 : {0:yyyy-MM-dd HH:mm:ss (dddd)}", dt);

            CultureInfo ciKo = new CultureInfo("ko-KR");
            WriteLine(dt.ToString("yyyy-MM-dd tt hh:mm:ss (ddd)", ciKo));
            WriteLine(dt.ToString("yyyy-MM-dd HH:mm:ss (dddd)", ciKo));
            WriteLine(dt.ToString(ciKo));

            CultureInfo ciEn = new CultureInfo("en-US");
            WriteLine(dt.ToString("yyyy-MM-dd tt hh:mm:ss (ddd)", ciEn));
            WriteLine(dt.ToString("yyyy-MM-dd HH:mm:ss (dddd)", ciEn));
            WriteLine(dt.ToString(ciEn));
        }

        static void ch4()
        {
            ArrayList a = null;
            a?.Add("야구");
            a?.Add("축구");
            WriteLine($"Count : {a?.Count}");
            WriteLine($"{a?[0]}");
            WriteLine($"{a?[1]}");

            a = new ArrayList();
            a?.Add("야구");
            a?.Add("축구");
            WriteLine($"Count : {a?.Count}");
            WriteLine($"{a?[0]}");
            WriteLine($"{a?[1]}");

            int temp = 1;
            WriteLine(temp);
            WriteLine(temp << 2);
            WriteLine(temp);

            int ?n = null;
            WriteLine($"{n ?? 0}");
            n = 5;
            WriteLine($"{n ?? 0}");

        }

        static void ch5()
        {

        }
        static void Main(string[] args)
        {
            //ch3();
            //appendix();
            //ch4();
            ch5();
        }

        
    }

    

}
