using System;

class Game
{

}

class Sandbox
{
    static void Main(string[] args)
    {
        unsafe
        {
            int* test = null;
        }
        Console.WriteLine("Test");
        Console.ReadKey();
    }
}
