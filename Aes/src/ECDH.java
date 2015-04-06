import java.util.Date;

/**
 * Created by alexpang on 2015/2/6.
 */
public class ECDH {
    private int g;
    private int p;
    private int priKey;
    private int pubKey;
    private int aesKey;
    private static int MinP = 10000;
    public ECDH(int P,int G){
        p = P;
        g = G;
        long currentTime = System.nanoTime();
        if (currentTime < 0 ) currentTime *= -1;
        priKey = (int)(currentTime %MinP) + 1;
        pubKey = Pow(g,priKey);
    }
    public static int generateP(){
        int P = 0;
        while(true)
        {
            long currentTime = System.nanoTime();
            if (currentTime < 0 ) currentTime *= -1;
            P = (int) (currentTime%MinP)  + MinP;
            if (isPrime(P)) return P;
        }

    }
    public static int generateG(int P){
        long currentTime = System.nanoTime();
        if (currentTime < 0 ) currentTime *= -1;
        int ans = (int)(currentTime % P);
        if (ans == 0) ans = 2;
        return ans;
    }
    public int getPubKey()
    {
        return pubKey;
    }
    public int generateAesKey(int pk){
        return aesKey = Pow(pk,priKey);
    }
    public int getAesKey()
    {
        return aesKey;
    }

    public static boolean isPrime(int num){
        if (num <= 1) return false;
        int tmp = (int)Math.sqrt((double)num);
        for (int i=2;i<=tmp;i++){
            if (num%i == 0) return false;
        }
        return true;
    }
    private int Pow(int a,int b){
        int ans = 1;
        a %= p;
        while(b != 0){
            if ((b&1) != 0){
                ans *= a;
                ans %= p;
            }
            a *= a;
            a %= p;
            b /= 2;
        }
        return ans;
    }

}
