#include <cstdint>
#include <string>
#include <vector>

namespace hw { namespace trezor { namespace messages { namespace qcoin {

struct qCoinStartRequest {};

struct qCoinStartResponse {
	std::string version;
	std::string wallet_key;
	std::string A_plus_sH;
	std::string v_mul_A_plus_sH;
	std::string view_public_key;
};

struct qCoinScanOutputsRequest {
	std::vector<std::string> output_public_key;
};

struct qCoinScanOutputsResponse {
	std::vector<std::string> Pv;
};

struct qCoinGenerateKeyimageRequest {
	std::string output_secret_hash_arg;
	uint32_t address_index = 0;
};

struct qCoinGenerateKeyimageResponse {
	std::string keyimage;
};

struct qCoinGenerateOutputSeedRequest {
	std::string tx_inputs_hash;
	uint32_t out_index = 0;
};

struct qCoinGenerateOutputSeedResponse {
	std::string output_seed;
};

struct qCoinExportViewWalletRequest {};

struct qCoinExportViewWalletResponse {
	std::string audit_key_base_secret_key;
	std::string view_secret_key;
	std::string view_seed;
	std::string view_secrets_signature;
};

struct qCoinSignStartRequest {
	uint32_t version      = 0;
	uint64_t ut           = 0;
	uint32_t inputs_size  = 0;
	uint32_t outputs_size = 0;
	uint32_t extra_size   = 0;
};

struct qCoinEmptyResponse {};

struct qCoinSignAddInputRequest {
	uint64_t amount = 0;
	std::vector<uint32_t> output_indexes;
	std::string output_secret_hash_arg;
	uint32_t address_index = 0;
};

struct qCoinSignAddOutputRequest {
	bool change              = false;
	uint64_t amount          = 0;
	uint32_t dst_address_tag = 0;
	std::string dst_address_S;
	std::string dst_address_Sv;
	uint32_t change_address_index = 0;
};

struct qCoinSignAddOutputResponse {
	std::string public_key;
	std::string encrypted_secret;
	uint32_t encrypted_address_type = 0;
};

struct qCoinSignAddExtraRequest {
	std::string extra_chunk;
};

struct qCoinSignStepARequest {
	std::string output_secret_hash_arg;
	uint64_t address_index = 0;
};

struct qCoinSignStepAResponse {
	std::string sig_p;
	std::string y;
	std::string z;
};

struct qCoinSignStepAMoreDataRequest {
	std::string data_chunk;
};

struct qCoinSignGetC0Request {};

struct qCoinSignGetC0Response {
	std::string c0;
};

struct qCoinSignStepBRequest {
	std::string output_secret_hash_arg;
	uint64_t address_index = 0;
	std::string my_c;
};

struct qCoinSignStepBResponse {
	std::string my_rr;
	std::string rs;
	std::string ra;
	std::string encryption_key;
};

struct qCoinStartProofRequest {
	uint32_t data_size = 0;
};

}}}}  // namespace hw::trezor::messages::qcoin

namespace protobuf {

typedef std::string::const_iterator iterator;

void read(::hw::trezor::messages::qcoin::qCoinEmptyResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinEmptyResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinExportViewWalletRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinExportViewWalletRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinExportViewWalletResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinExportViewWalletResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinGenerateKeyimageRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateKeyimageRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinGenerateKeyimageResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateKeyimageResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinScanOutputsRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinScanOutputsRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinScanOutputsResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinScanOutputsResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinSignAddExtraRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddExtraRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignAddInputRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddInputRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignAddOutputRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddOutputRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignAddOutputResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddOutputResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinSignGetC0Request &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignGetC0Request &v);

void read(::hw::trezor::messages::qcoin::qCoinSignGetC0Response &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignGetC0Response &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStartRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStartRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStepAMoreDataRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepAMoreDataRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStepARequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepARequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStepAResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepAResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStepBRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepBRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinSignStepBResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepBResponse &v);

void read(::hw::trezor::messages::qcoin::qCoinStartProofRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinStartProofRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinStartRequest &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinStartRequest &v);

void read(::hw::trezor::messages::qcoin::qCoinStartResponse &v, iterator s, iterator e);
std::string write(const ::hw::trezor::messages::qcoin::qCoinStartResponse &v);

}  // namespace protobuf
