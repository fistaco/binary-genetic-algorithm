public class GeneticAlgorithm {

    private int popSize;
    private int gens;
    private CrossoverType crossoverType;
    private float crossoverRate;
    private float mutationRate;
    private float optimalFitness;

    public GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness) {
        this.popSize = popSize;
        this.gens = gens;
        this.crossoverType = crossoverType;
        this.crossoverRate = crossoverRate;
        this.mutationRate = mutationRate;
        this.optimalFitness = optimalFitness;
    }

    public void run() {

    }
}
