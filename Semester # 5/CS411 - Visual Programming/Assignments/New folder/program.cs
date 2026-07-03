using System;

class Products
{
  protected string P_name;
  protected double P_price;
  protected int P_Qty;

  public string Name
  {
    get { return P_name; }
    set { P_name = value; }
  }

  public double Price
  {
    get { return P_price; }
    set { P_price = value; }


  }

  public int Quantity
  {
    get { return P_Qty; }
    set { P_Qty = value; }
  }

  public Products()
  {
    P_name = "";
    P_price = 0;
    P_Qty = 0;
  }

  public virtual void Display()
  {
    Console.WriteLine("Product Name: " + P_name);
    Console.WriteLine("Product Price: " + P_price);
    Console.WriteLine("Product Qty: " + P_Qty);
  }
}


class Electronics : Products
{
  private int warranty;

  public Electronics(string name, double price, int qty, int warrantyYears)
  {
    P_name = name;
    P_price = price;
    P_Qty = qty;
    warranty = warrantyYears;
  }

  public override void Display()
  {
    Console.WriteLine("<==== call Electronic class verison of Display ===>");
    Console.WriteLine("Product Name: " + P_name);
    Console.WriteLine("Product Price: " + P_price);
    Console.WriteLine("Product Qty: " + P_Qty);
    Console.WriteLine("Warranty: " + warranty + " years");

  }

}

class Clothing : Products
{
  private double size;

  public Clothing(string name, double price, int qty, double sizeValue)
  {
    P_name = name;
    P_price = price;
    P_Qty = qty;
    size = sizeValue;
  }

  public override void Display()
  {
    Console.WriteLine("<==== call Clothing class verison of Display ===>");
    Console.WriteLine("Product Name: " + P_name);
    Console.WriteLine("Product Price: " + P_price);
    Console.WriteLine("Product Qty: " + P_Qty);
    Console.WriteLine("Size: " + size);
  }

}


class Program
{
  static void Main(string[] args)
  {
    Products p;

    p = new Electronics("Air Conditioner", 70000, 20, 5);
    p.Display();

    Console.WriteLine();

    p = new Clothing("T-Shirt", 1200, 45, 35.5);
    p.Display();

    Console.ReadLine();
  }
}





