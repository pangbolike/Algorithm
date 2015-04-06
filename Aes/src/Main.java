import javax.crypto.KeyGenerator;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.util.Date;

/**
 * Created by alexpang on 2015/2/6.
 */
public class Main {


    public static void main(String args[]){
        long time = System.nanoTime();
        int p = ECDH.generateP();
        int g = ECDH.generateG(p);
        ECDH ecdh1 = new ECDH(p,g);
        ECDH ecdh2 = new ECDH(p,g);
        ecdh1.generateAesKey(ecdh2.getPubKey());
        ecdh2.generateAesKey(ecdh1.getPubKey());
        String ss = "我是一个粉刷匠！";
        byte[] content = AES.Encrypt(ss,ecdh1.getAesKey()+"");
        System.out.println(AES.Decrypt(content,ecdh2.getAesKey()+""));
        System.out.println(System.nanoTime() - time);
        System.out.println(System.nanoTime());

    }
}
