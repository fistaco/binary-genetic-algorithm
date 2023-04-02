import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class GeneticAlgorithm {

    private int popSize;
    private int gens;
    private CrossoverType crossoverType;
    private double crossoverRate;
    private double mutationRate;
    private float optimalFitness;

    private Genome[] population;

    private Random random;

    public GeneticAlgorithm(int popSize, int gens, CrossoverType crossoverType, double crossoverRate, double mutationRate, float optimalFitness) {
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
	private void produceOffspring() throws Exception {
        // Store offspring in the second half of the population in pairs of two
        for (int i = this.popSize/2; i < this.popSize; i += 2) {
            // Choose two random parents from the top half of the population
            Genome parent0 = this.population[this.random.nextInt(this.popSize/2)];
            Genome parent1 = this.population[this.random.nextInt(this.popSize/2)];
            ArrayList<Genome> children;

            // Apply crossover and mutation with the given probabilities
            double r = this.random.nextDouble();
            if (r < this.crossoverRate) {
                children = parent0.crossover(parent1, crossoverType);
            }
            else {
                // If crossover is not applied, use the unmodified parents as children
                children = new ArrayList<Genome>(List.of(parent0.clone(), parent1.clone()));
            }

            if (r < this.mutationRate) {
                children.get(0).mutate();
                children.get(1).mutate();
            }

            this.population[i] = children.get(0);
            this.population[i + 1] = children.get(1);
        }
    }

}
