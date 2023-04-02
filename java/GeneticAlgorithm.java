import java.util.Random;

public class GeneticAlgorithm {

    private int popSize;
    private int gens;
    private CrossoverType crossoverType;
    private float crossoverRate;
    private float mutationRate;
    private float optimalFitness;

    private Genome[] population;

    private Random random;

    public GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, float crossoverRate, float mutationRate, float optimalFitness) {
        this.popSize = popSize;
        this.gens = gens;
        this.crossoverType = crossoverType;
        this.crossoverRate = crossoverRate;
        this.mutationRate = mutationRate;
        this.optimalFitness = optimalFitness;

        this.population = new Genome[popSize];

        this.random = new Random();
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
     * Selects fit genomes through repeated fitness-based tournaments of {@code tournamentSize}
     * randomly chosen genomes. 
     * 
     * @param tournamentSize
     */
    private void tournamentSelect(int tournamentSize) {
        int halfPopSize = this.popSize/2;
        Genome[] selectedGenomes = new Genome[halfPopSize]; // Store winners until selection is over

        // Hold tournaments until half of the population is filled
        for (int i = 0; i < halfPopSize; i++) {
            float bestFitness = -1.0f;
            Genome winner = null;

            // Randomly choose 3 participants and compare their fitness values
            for (int j = 0; j < tournamentSize; j++) {
                Genome participant = this.population[this.random.nextInt(this.popSize)];
                float fitness = participant.getFitness();

                if (fitness > bestFitness) {
                    bestFitness = fitness;
                    winner = participant;
                }
            }

            selectedGenomes[i] = winner;
        }

        // Replace the top half of the population with the winners
        for (int i = 0; i < halfPopSize; i ++) {
            this.population[i] = selectedGenomes[i];
        }
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

}
