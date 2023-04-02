import java.util.ArrayList;
import java.util.Random;


public class BinaryString extends Genome {

    public int[] bits;

    /**
     * Constructs a binary string of the given {@code size} initialised with
     * zeros.
     * 
     * @param size
     */
    public BinaryString(int size) {
        this.bits = new int[size];
        for (int i = 0; i < size; i++) {
            this.bits[i] = 0;
        }
    }

    /**
     * Flips a randomly selected bit of this binary string with the given probability.
     */
    @Override
    public void mutate() {
        int randomIndex = (int) (Math.random() * this.bits.length);
        this.bits[randomIndex] ^= 1;  // 0 XOR 1 == 1, 1 XOR 1 == 0
    }

    @Override
    public ArrayList<Genome> crossover(Genome other) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'crossover'");
    }

    @Override
    public BinaryString clone() {
        BinaryString clone = new BinaryString(this.bits.length);
        for (int i = 0; i < this.bits.length; i ++) {
            clone.bits[i] = this.bits[i];
        }

        return clone;
    }

    @Override
    public void print() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'print'");
    }
    
    /**
     * Returns a binary strings of the given {@code size} with its bits randomly set to 0 or 1.
     * 
     * @param size
     */
    public static BinaryString random(Random rng, int size) {
        BinaryString binString = new BinaryString(size);

        for (int i = 0; i < size; i ++) {
            binString.bits[i] = rng.nextInt(2);
        }

        return binString;
    }

    @Override
    public float computeFitness() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'computeFitness'");
    }
}
