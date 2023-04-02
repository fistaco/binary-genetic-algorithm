public class GeneticAlgorithm {

    private int popSize;
    private int gens;
    private CrossoverType crossoverType;
    private float crossoverRate;
    private float mutationRate;
    private float optimalFitness;

    private Genome[] population;

    public GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness) {
        this.popSize = popSize;
        this.gens = gens;
        this.crossoverType = crossoverType;
        this.crossoverRate = crossoverRate;
        this.mutationRate = mutationRate;
        this.optimalFitness = optimalFitness;

        this.population = new Genome[popSize];
    }

    public void run() {
        this.initialisePopulation();

        Genome bestGenome = this.population[0];
        float bestFitness = 0.0f;  // Assume fitness maximisation

        int gen = 0;
        while (gen < this.gens) {
            // Evaluate fitness values and track the best genome
            this.evaluateFitness();
            this.selectGenomes();
            this.produceOffspring();

            gen++;
        }

        // Print results
        System.out.println(String.format("Best genome's fitness after %d generations: %f", gen, bestFitness));
        System.out.println("Best genome: ");
        bestGenome.print();
    }

    private void initialisePopulation() {

    }

    /**
     * Computes and sets the fitness of each genome in the population.
     */
    private void evaluateFitness() {
        for (Genome genome : population) {
            genome.setFitness(genome.computeFitness());
        }
    }

    /**
     * Selects the fittest genomes as parents for the next generation by placing them in the first
     * 50% of indices in the population.
     */
	private void selectGenomes() {
        this.tournamentSelect(3);
    }

    /**
     * Produces offspring according to the chosen crossover type for this GA by using the parent
     * genomes that we assume to be in the first half of the population. The offspring is then
     * placed in the second half.
     * 
     * @param crossoverType
     */
	private void produceOffspring() {
    }

    /**
     * Selects fit genomes through repeated fitness-based tournaments of {@code tournamentSize}
     * randomly chosen genomes. 
     * 
     * @param tournamentSize
     */
	private void tournamentSelect(int tournamentSize) {

    }


}
