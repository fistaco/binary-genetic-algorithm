public class GeneticAlgorithm {

    private int popSize;
    private int gens;
    private float crossoverRate;
    private float mutationRate;
    private float optimalFitness;

    public GeneticAlgorithm(int popSize, int gens, float crossoverRate, float mutationRate, float optimalFitness) {
        this.popSize = popSize;
        this.gens = gens;
        this.crossoverRate = crossoverRate;
        this.mutationRate = mutationRate;
        this.optimalFitness = optimalFitness;
    }
}
