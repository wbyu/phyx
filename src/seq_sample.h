#ifndef _BOOT_H_
#define _BOOT_H_

class SequenceSampler {
private:
    float jkfract;
    bool jackknife;
    bool partitioned;
    vector <int> samplesites;
    vector < vector <int> > partitions;
    vector <string> partitionNames;
    vector <int> sitePartitions; // not used
    int numPartitionedSites;
    int numPartitions;
    
    vector <int> get_bootstrap_sites (int const& numchar);
    vector <int> get_jackknife_sites (int const& numchar);
    vector <int> get_partitioned_bootstrap_sites ();
    
    void parse_partitions (string & partf);
    void get_partition_parameters (vector <string> & tokens, int & start, int & stop, int & interval);
    vector <int> get_partition_sites (string const& part);
    void check_valid_partitions ();
    void calculate_num_partitioned_sites ();
    void get_site_partitions (); // not used
    
    void find_duplicates_missing (vector <int> const& allSites);

public:
    SequenceSampler (int const& seed, float const& jackfract, string & partf);
    vector <int> get_sampled_sites ();
    void sample_sites (int const& numchar);
    string get_resampled_seq (string const& origseq);
    int get_num_partitioned_sites ();
    //~SequenceResampler();
};

#endif /* _BOOT_H_ */