# Designs


## HashMap

- hash function design: the purpose of hash function is to map a key value to an address in the storage space, similarly to the system that we assign a postcode to each mail address.
As one can image, for a good hash function, it should map different keys evenly across the storage space, so that we don't end up with the case that the majority of the keys are concentrated in a few spaces.

- collision handling: essentially the hash function reduces the vast key space into a limited address space. As a result, there could be the case where two different keys are mapped to the same address, which is what we call 'collision'. Since the collision is inevitable, it is important that we have a strategy to handle the collision.

## HashSet

- Separate Chaining: for values with the same hash key, we keep them in a bucket, and each bucket is independent of each other.

- Open Addressing: whenever there is a collision, we keep on probing on the main space with certain strategy until a free slot is found.

- 2-Choice Hashing: we use two hash functions rather than one, and we pick the generated address with fewer collision.

Essentially, the primary storage underneath a HashSet is a continuous memory as Array. Each element in this array corresponds to a bucket that stores the actual values. Given a value, first we generate a key for the value via the hash function. The generated key serves as the index to locate the bucket. Once the bucket is located, we then perform the desired operations on the bucket, such as add, remove and contains.

