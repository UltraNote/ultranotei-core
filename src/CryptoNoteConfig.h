// Copyright (c) 2011-2017 The Cryptonote Developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
// Copyright (c) 2018-2020 UltraNote Network & UlraNote Devs
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>
#include <map>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x2de638; /* Xuni address prefix */
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 10; /* 20 minutes */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 60 * 60 * 2; /* two hours */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1 = 360; /* changed for LWMA3 */
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE = 10; /* 20 minutes */

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 30;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1 = 11; /* changed for LWMA3 */

const uint64_t MONEY_SUPPLY = UINT64_C(21000000000000); /* max supply: 21M */

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE = 100000; /* size of block in bytes, after which reward is calculated using block size */
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT = 6;

const uint64_t POINT = UINT64_C(1000); 
const uint64_t COIN = UINT64_C(1000000); /* smallest atomic unit */
const uint64_t MINIMUM_FEE = UINT64_C(1000); /* 0.001000 xuni */
const uint64_t MINIMUM_FEE_BANKING = UINT64_C(1000); /* 0.001000 xuni */
const uint64_t DEFAULT_DUST_THRESHOLD = UINT64_C(10); /* 0.000010 xuni */  

const uint64_t DIFFICULTY_TARGET = 120; /* two minutes */
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET; /* 720 blocks */
const size_t   DIFFICULTY_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
const size_t   DIFFICULTY_WINDOW_V1 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V3 = 60; /* changed for LWMA3 */
const size_t   DIFFICULTY_BLOCKS_COUNT = DIFFICULTY_WINDOW_V3 + 1; /* added for LWMA3 */
const size_t   DIFFICULTY_CUT = 60; /* timestamps to cut after sorting */
const size_t   DIFFICULTY_CUT_V1 = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2 = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG = 15; 
const size_t   DIFFICULTY_LAG_V1 = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2 = DIFFICULTY_LAG;


static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT 							= 1 * COIN; 
const uint32_t DEPOSIT_MIN_TERM 							= 22000; /* one month */
const uint32_t DEPOSIT_MAX_TERM 							= 1 * 12 * 22000; /* one year */
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR 				= 0; /* constant rate */
const uint64_t DEPOSIT_MAX_TOTAL_RATE 						= 3; /* 3% per annual */

static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR 							 = 10; /* Early Adopters */
const uint32_t END_MULTIPLIER_BLOCK 						 = 3600; /* legacy deposits */

const size_t   MAX_BLOCK_SIZE_INITIAL = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR 		 = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR 		 = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS 	 = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT = (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE; /* maximum transaction size */
const size_t   CRYPTONOTE_OPTIMIZE_SIZE 					 = 100; /* proportional to CRYPTONOTE_MAX_TX_SIZE_LIMIT */

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME 				 = (60 * 60 * 12); /* 12 hours in seconds */
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); /* 23 hours in seconds */
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL  = 7; /* CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME  = time to forget tx */

const size_t   FUSION_TX_MAX_SIZE = CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT 					= 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO 			= 4;

const uint64_t UPGRADE_HEIGHT 								= 1;			
const uint64_t UPGRADE_HEIGHT_V2							= 1;
const uint64_t UPGRADE_HEIGHT_V3 							= 2; 

const unsigned UPGRADE_VOTING_THRESHOLD = 90; // percent
const size_t   UPGRADE_VOTING_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
const size_t   UPGRADE_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[] 				  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[] 			  = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[] 			  = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[] 				  = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[] 						  = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]       = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                       = "miner_conf.json";

} // parameters

const uint64_t START_BLOCK_REWARD 							  = (UINT64_C(5) * parameters::COIN); // start reward
const uint64_t FOUNDATION_TRUST 							  = (UINT64_C(2100000) * parameters::COIN); // 2.1M locked funds to secure network
const uint64_t MAX_BLOCK_REWARD 							  = (UINT64_C(10) * parameters::COIN); // max reward after 12 months
const uint64_t REWARD_INCREASE_INTERVAL 					  = (UINT64_C(22000)); // aprox. 1 month (+ 0.4 xuni increment per month)

const char     CRYPTONOTE_NAME[] 							  = "ultranotei";
const char     GENESIS_COINBASE_TX_HEX[] 					  = "010a01ff0001c096b102029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121018defaf357ba96274bf7c0aa07cca61025e710e829efb9c5d9af9f067b8882990";
const uint32_t GENESIS_NONCE = 10000;
const uint64_t GENESIS_TIMESTAMP 							  = 1587360548; // 20200420

const uint8_t  TRANSACTION_VERSION_1 						  = 1; 
const uint8_t  TRANSACTION_VERSION_2 						  = 2; 

const uint8_t  BLOCK_MAJOR_VERSION_1 						  = 1; // (V1) 
const uint8_t  BLOCK_MAJOR_VERSION_2 						  = 2; // (V2) 
const uint8_t  BLOCK_MAJOR_VERSION_3 						  = 3; // (V3)

const uint8_t  BLOCK_MINOR_VERSION_0 = 0; 
const uint8_t  BLOCK_MINOR_VERSION_1 = 1; 

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;

const int      P2P_DEFAULT_PORT = 42000;
const int      RPC_DEFAULT_PORT = 43000;


/* P2P Network Configuration Section - This defines our current P2P network version
and the minimum version for communication between nodes */
const uint8_t  P2P_CURRENT_VERSION = 1;
const uint8_t  P2P_MINIMUM_VERSION = 1;
const uint8_t  P2P_UPGRADE_WINDOW  = 2;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 64 * 1024 * 1024;   // 64MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70;            // percent
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL = 60;                       // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE = 50000000;                    // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT = 5000; 					  // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[] = "e9a5f0d30549afde49c9bfbaa52ac60afdc46304642b460a9ea34bf7a4ef7061";

// Seed Nodes
const std::initializer_list<const char*> SEED_NODES  = {
   "45.63.58.18:42000",
   "139.180.136.6:42000",
   "155.138.140.208:42000",
   "45.32.206.198:42000",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// Blockchain Checkpoints:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS  = {

 {0, "b87145f2d92e8dbee77e431dfe1f6ce92fd91077e065cb042f751d3a9541ba62"},
 {1000, "083729e0be52246f19d1da23fbe5f96b4e3948e5effd705179d38131041a96d5"},
 {2000, "f3433995e2203a1908133622ef0802b152955c7a1ce605f1e9251bc817e38b09"},
 {3000, "79421be1ef1a0e590e8749decdcc551cbc4125265d6d939be61b4d6c46ca4b37"},
 {4000, "af43cc12cbb8ec47ea08245ccde29ff3a29f68f6f295bb2034437f0c101a67b1"},
 {5000, "40a860cfb519f2ce479d04f8c5c1872f8f79fa5903254071742678369484421b"},
 {6000, "b94a1065693123f16615d207523a03bed5f484b7b0030f62f030efc7f01a4ebf"},
 {7000, "b67e9057cf96b0aca0bd575a002d4376402ce47196b68b42b8ee0780e119ba45"},
 {8000, "40b206b2eaf8926f6e6282cd0984080718a14e41979a25df7d1f760316f25119"},
 {9000, "f68164192390ec50a4c1a0824de4996cf6a2a238dbdacd2aae1f6520b2850962"},
 {10000, "ebdb99611acc9b6d2f0c9fffae5a467e8a420e29189449f7f8e09b0f5fc1e1c4"},
 {11000, "2e772769a517cd302bf94e97803817c413df2976edd5ecaf1ece84df6ac5c082"},
 {12000, "45ce9d710a845b0fd00497031aa470e02cef889269dc3412ab0af8437018b9cb"},
 {13000, "5fa5db9c4a76ce32691c7631bd2573b9e0d3c5ff0ef23f9252a33f253cd611e9"},
 {14000, "82a80f5732141ac2352bcdb22ded56e507810caee8128c66e7e128a8e85a3105"},
 {15000, "7ce3bd474371b1999f6fc9c326d1736772500c382798ce6e7d43d894832da9ec"},
 
 // version 1.0.2
 
 {16000, "8a256c9125a60419f2fb14de6c2e2f3ffc208a70a2f848d9690d9cd582d39031"},
 {17000, "bee5fe19e0242c6d87256a5efaa0430bdd38c576d678bdbd52a5b00c55130a8d"},
 {18000, "4e4bea66c6d12f226684fbaf87eb9f6bdedaf2158957b52b5d1cf189a7058bb2"},
 {19000, "91dbf1cebcf0323397928a2e4473d5e555e76ee9234dd1a1b1890160b14da708"},
 {20000, "4f75d7ea3c116e6ebbd37edc472b79bb9551e9be2801564a1b4be9e2689dcd82"},
 {21000, "b38812e690d5fd738d5bf737990cf4597e62f718cc304574443e58d18297f508"},
 {22000, "05f0e7480053c167fd7eb8600ebad707abdc167c06b4e5fd31c763184ae5cdf0"},
 {23000, "1f266cadefe8d02e439e9acdfdf790eeb1c5d6e987d4414905376afd4df14c33"},
 {24000, "ad86d75b0bdda9fa0c6781c6ee9d9db0566c6ab09fd602a323d4b6b710d4e5f8"},
 {25000, "bb8bd3c62ced4018f0b7c8894142353a64d2d415bb0e816fec77b36f1ab6e128"},
 {26000, "3c24d434abeda12154bda48947f931d39bec5a7e4e3e17b62528815e891903dd"},
 {27000, "1ebe055542822e6501a2b9db9b9bb17da617e7d91f740b9df6e6f2e2739a2204"},
 {28000, "d095e0b1bbc371019f8eedab0f42122bf024df87078db14585decad951cc62d4"},
 {29000, "ccc67b0d94e201223f6d0d05cf6d78b867f94a43c3d7020880181f55c62fb299"},
 {30000, "8f54018897d4a2109d3f54810d5c36030b1d597de9e6dc04c9dd22f472664ed2"},
 {31000, "20ddbafdd31afe17a5515c30479506380b0be4bbd9f72e225925d0d906eeba31"},
 {32000, "69559b8f877a83b34d7f8392d27748410535d0fcbca90a194e654b1af09b9605"},
 {33000, "e5a0f221ae112677527272f92257e69386990a6ac9221fa7f05decd5b8f9b17a"},
 {34000, "2bbb74acc78aed072d5e08444ec8e5e041eace6037e051f7c484dac18dc87727"},
 {35000, "184b593a15438b0136413c5da48cb6ba12aeac21af81cb732eecedf0ec09815a"},
 {36000, "aad80b1f81ba905232f92cb78b2c23222fc4e062332f72fafde4f87c12e20bf6"},
 {37000, "2b09b4d6789ddd4874f4ed50806f785aec200cdd6acc636d7a5e0a155d1c93e6"},
 {38000, "1c4d1fb1e26d8c54320b279217babc3bfb4bd31507c84cbf24c6e74615315c9d"},
 {39000, "9a97ed51be3416f968c86b81cf0fb3b6de68b25e35ee7f024098b9d004085006"},
 {40000, "e9dddac678a339e4b59f8fe647a5bc7b263f1ebfa92a56b44087935b11e16696"},
 {41000, "8547a1c018b9152e56c84d61ae0fe84fc516e56b6c13de809c39ffc892938581"},
 {42000, "738d55a9e4a070bedfb089d2701da357c8fe81c17e43cae4bfc5f7a525b8fe1e"},
 {43000, "2d16a1374dd740db480e2990458ae673762bedbe70d8b00a420fe679eb746676"},
 {44000, "68254d51e921dddca8bd004b1aaf0368ccd152075b91d6b1ae50a46c998259f7"},
 {45000, "c3fe93ce44f6a83368d4ccdcfda4318f86f81dff7a18e5cd368a835b56cae9de"},
 {46000, "7e6a3fb703468f8dfbddd38f371aae01c4a7566e0f00ba32df43c66ade28a803"},
 {47000, "c9cebc75a9817ff2a345cd6d8d470a1d17148826d613a7535aada3901e06dd7a"},
 {48000, "a8a0d644171a4e581590f6907a7e29971f1fda9cbc3da2ec3b0a83100ec8ac0c"},
 {49000, "1075ff9963624c03e39d39883b9707689fc46cb87c45bb069c8a2245226ba0dc"},
 {50000, "cf75b17ea35abd19285c9a6f3de145efa3a77f583ebf6629460aa170d72a602e"}, 
 {51000, "e6d6210f2ee96083deec431bd730159450cccd7ed07772628648a536177b1467"},
 {52000, "45b8f979085e09da5d3f7755ff1d941e923e2f6a311013330feeb6b826f3c290"},
 {53000, "71d6c5bf2f8a840738598409876b223e2cc21502a7c15e198a69472e65836297"},
 {54000, "bea9246d94ccdf8909213d371d07d2ba599149a51aabe63a202021266d7a961e"}, 
 {55000, "96d09e12de9391fb28f026783fc684b8b3ae4f651a54633aa3071fdd6d59c507"}, 
 {56000, "643f62e472768f49f6d92031222f38a879c33943825421ffdbcbe6953be93016"},
 {57000, "dabeb5bd0c4daf3fc8f0e79a85feba9437bc8d72f1d65073b74c4f3298e245de"},
 {58000, "eb73d94b6cbbafdcb496ad1c3bd39849946b3ca100e449671d3994453cdaf564"},
 {59000, "a8328ff6a67b65f15f074f4465e88a6f11826aa7fd95ffd795c5a0a9574ec9db"},
 {60000, "603bb733a2797c59b8c034fa30c19eeb878433d4e6614283aee54f9f43c7583c"},
 {61000, "dc8090fa182fa14e06c32c45a9330f7c82a6e5ef67af2d0b4839c0c1fec86b1e"},
 {62000, "8e35b860cef8295931c327d8e267387491d0cbdd3253784bec9a194a97c4ec90"},
 {63000, "bba41d4ae67e585dc381fbd13cfdef9cc2e3fb371e4b8c705cffc327695b0924"},
 {64000, "e2377f67708a838e8f4f0a01be6d9bd7a075358f9575ad000ad42399d586bd68"},
 {65000, "62f627d96692f565b908e878a8649a6dfc888065e890d318e9e5cc839ff18250"},
 {66000, "e2a4043720a8b1dba7cda4c34f6b66065c6959ab9d25e90bf35d869660499d67"},
 
};


} // CryptoNote

#define ALLOW_DEBUG_COMMANDS