#u20734621 - Matthew Gotte
#StockItem Class
class StockItem
       def initialize(n, prc)
           @name = n
           @price = prc
       end
       def setName(n)
           @name = n
       end
       def setPrice(prc)
           @price = prc
       end
       def getPrice
           put "cannot get abstract price."
       end
       def getName
           return @name
       end
   end
   #Shop Class
   class Shop
       @stock = StockItem.new("", 0)
       def initialize()
           @stock = []
       end
       def addStockItem(newItem, name)
           @stock << newItem
           newItem.setName(name)
       end
       def setPrice(name, prc)
           @stock.each do |i|
               if i.getName == name
                     i.setPrice(prc)
               end
           end
       end
       def getAveragePrice()
           total = 0
           @stock.each do |i|
               total += i.getPrice
           end
           total = total / @stock.length
           return total.round(2)
       end
       def print
           puts "Items"
           @stock.each do |i|
               puts "#{i.getName}: R#{i.getPrice}\n"
           end
       end
   end
   #NormalPriceItem Class
   class NormalPriceStockItem < StockItem
       def initialize(n, pr)
           super(n, pr)
       end
       def getPrice
           return @price
       end
   end
   #DiscountStockItem Class
   class DiscountedStockItem < StockItem
       def initialize(n, pr)
           super(n, pr)
       end
       def getPrice
           return @price * 1 - 0.1
       end
   end
   #create Counter
   counter = 1
   #create Shop
   shop = Shop.new
   while counter < 4
       print "Name for item #{counter}: "
       name = gets.chomp
       print "Price for item #{counter}: "
       price = gets.chomp.to_f
       print "Type for item #{counter} (d = discount / n = normal): "
       itype = gets.chomp
       if itype == "N" || itype == "n"
           item = NormalPriceStockItem.new(name, price)
       else
           item = DiscountedStockItem.new(name, price) 
       end
       shop.addStockItem(item, name)
       counter += 1
   end
   puts ""
   shop.print
   puts "\nAverage = R#{shop.getAveragePrice}"
   
   
   
   