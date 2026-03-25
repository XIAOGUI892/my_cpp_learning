
class Outer{
private:
    int x;
    Inner inner;
public:
    int Getx()const{
        return x;
    }
    class Inner{
    private:
        int y;
    public:
        int readx(const Outer &outer){
            return outer.Getx();
        }
    }
    
}



