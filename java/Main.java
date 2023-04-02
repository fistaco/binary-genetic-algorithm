import java.util.List;
import java.util.Random;

/**
 * The class from which the program starts.
 */
public class Main {

    public static void main(String[] args) {
        var popSize = 32;
        var gens = 50;
        var crossoverType = CrossoverType.UNIFORM;
        var crossoverRate = 0.7;
        var mutationRate = 0.7;
        var binaryStringLength = 8;
        var optimalFitness = binaryStringLength;
        var genomeType = GenomeType.BINARYSTRING;
        List<Object> genomeInitialisationArgs = List.of(binaryStringLength);

        var geneticAlgorithm = new GeneticAlgorithm(
            popSize,
            gens,
            crossoverType,
            crossoverRate,
            mutationRate,
            optimalFitness,
            genomeType
        );

        try {
            geneticAlgorithm.run(genomeInitialisationArgs);
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}