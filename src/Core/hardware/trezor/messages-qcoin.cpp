#include "messages-qcoin.hpp"
#include "protobuf.hpp"

namespace protobuf {

void read(::hw::trezor::messages::qcoin::qCoinStartRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m          = read_varint(&s, e);
		auto field_type = static_cast<unsigned>(m & 7);
		skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinStartRequest &v) {
	std::string s;
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinStartResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.version = read_string(&s, e);
		else if (field_number == 2 && field_type == 2)
			v.wallet_key = read_string(&s, e);
		else if (field_number == 3 && field_type == 2)
			v.A_plus_sH = read_string(&s, e);
		else if (field_number == 4 && field_type == 2)
			v.v_mul_A_plus_sH = read_string(&s, e);
		else if (field_number == 5 && field_type == 2)
			v.view_public_key = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinStartResponse &v) {
	std::string s;
	if (!v.version.empty())
		write_field_string(1, v.version, s);
	if (!v.wallet_key.empty())
		write_field_string(2, v.wallet_key, s);
	if (!v.A_plus_sH.empty())
		write_field_string(3, v.A_plus_sH, s);
	if (!v.v_mul_A_plus_sH.empty())
		write_field_string(4, v.v_mul_A_plus_sH, s);
	if (!v.view_public_key.empty())
		write_field_string(5, v.view_public_key, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinScanOutputsRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.output_public_key.push_back(read_string(&s, e));
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinScanOutputsRequest &v) {
	std::string s;
	for (const auto &vv : v.output_public_key)
		write_field_string(1, vv, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinScanOutputsResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.Pv.push_back(read_string(&s, e));
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinScanOutputsResponse &v) {
	std::string s;
	for (const auto &vv : v.Pv)
		write_field_string(1, vv, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinGenerateKeyimageRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.output_secret_hash_arg = read_string(&s, e);
		else if (field_number == 2 && field_type == 0)
			v.address_index = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateKeyimageRequest &v) {
	std::string s;
	if (!v.output_secret_hash_arg.empty())
		write_field_string(1, v.output_secret_hash_arg, s);
	if (v.address_index != 0)
		write_field_varint(2, v.address_index, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinGenerateKeyimageResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.keyimage = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateKeyimageResponse &v) {
	std::string s;
	if (!v.keyimage.empty())
		write_field_string(1, v.keyimage, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.tx_inputs_hash = read_string(&s, e);
		else if (field_number == 2 && field_type == 0)
			v.out_index = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedRequest &v) {
	std::string s;
	if (!v.tx_inputs_hash.empty())
		write_field_string(1, v.tx_inputs_hash, s);
	if (v.out_index != 0)
		write_field_varint(2, v.out_index, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.output_seed = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinGenerateOutputSeedResponse &v) {
	std::string s;
	if (!v.output_seed.empty())
		write_field_string(1, v.output_seed, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinExportViewWalletRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m          = read_varint(&s, e);
		auto field_type = static_cast<unsigned>(m & 7);
		skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinExportViewWalletRequest &v) {
	std::string s;
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinExportViewWalletResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.audit_key_base_secret_key = read_string(&s, e);
		else if (field_number == 2 && field_type == 2)
			v.view_secret_key = read_string(&s, e);
		else if (field_number == 3 && field_type == 2)
			v.view_seed = read_string(&s, e);
		else if (field_number == 4 && field_type == 2)
			v.view_secrets_signature = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinExportViewWalletResponse &v) {
	std::string s;
	if (!v.audit_key_base_secret_key.empty())
		write_field_string(1, v.audit_key_base_secret_key, s);
	if (!v.view_secret_key.empty())
		write_field_string(2, v.view_secret_key, s);
	if (!v.view_seed.empty())
		write_field_string(3, v.view_seed, s);
	if (!v.view_secrets_signature.empty())
		write_field_string(4, v.view_secrets_signature, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStartRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 0)
			v.version = read_varint_t<uint32_t>(&s, e);
		else if (field_number == 2 && field_type == 0)
			v.ut = read_varint(&s, e);
		else if (field_number == 3 && field_type == 0)
			v.inputs_size = read_varint_t<uint32_t>(&s, e);
		else if (field_number == 4 && field_type == 0)
			v.outputs_size = read_varint_t<uint32_t>(&s, e);
		else if (field_number == 5 && field_type == 0)
			v.extra_size = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStartRequest &v) {
	std::string s;
	if (v.version != 0)
		write_field_varint(1, v.version, s);
	if (v.ut != 0)
		write_field_varint(2, v.ut, s);
	if (v.inputs_size != 0)
		write_field_varint(3, v.inputs_size, s);
	if (v.outputs_size != 0)
		write_field_varint(4, v.outputs_size, s);
	if (v.extra_size != 0)
		write_field_varint(5, v.extra_size, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinEmptyResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m          = read_varint(&s, e);
		auto field_type = static_cast<unsigned>(m & 7);
		skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinEmptyResponse &v) {
	std::string s;
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignAddInputRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 0)
			v.amount = read_varint(&s, e);
		else if (field_number == 2 && field_type == 2)
			read_packed_varint(v.output_indexes, &s, e);
		else if (field_number == 2 && field_type == 0)
			v.output_indexes.push_back(read_varint_t<uint32_t>(&s, e));
		else if (field_number == 3 && field_type == 2)
			v.output_secret_hash_arg = read_string(&s, e);
		else if (field_number == 4 && field_type == 0)
			v.address_index = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddInputRequest &v) {
	std::string s;
	if (v.amount != 0)
		write_field_varint(1, v.amount, s);
	for (const auto &vv : v.output_indexes)
		write_field_varint(2, vv, s);
	if (!v.output_secret_hash_arg.empty())
		write_field_string(3, v.output_secret_hash_arg, s);
	if (v.address_index != 0)
		write_field_varint(4, v.address_index, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignAddOutputRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 0)
			v.change = read_varint(&s, e) != 0;
		else if (field_number == 2 && field_type == 0)
			v.amount = read_varint(&s, e);
		else if (field_number == 3 && field_type == 0)
			v.dst_address_tag = read_varint_t<uint32_t>(&s, e);
		else if (field_number == 4 && field_type == 2)
			v.dst_address_S = read_string(&s, e);
		else if (field_number == 5 && field_type == 2)
			v.dst_address_Sv = read_string(&s, e);
		else if (field_number == 6 && field_type == 0)
			v.change_address_index = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddOutputRequest &v) {
	std::string s;
	if (v.change)
		write_field_varint(1, v.change ? 1 : 0, s);
	if (v.amount != 0)
		write_field_varint(2, v.amount, s);
	if (v.dst_address_tag != 0)
		write_field_varint(3, v.dst_address_tag, s);
	if (!v.dst_address_S.empty())
		write_field_string(4, v.dst_address_S, s);
	if (!v.dst_address_Sv.empty())
		write_field_string(5, v.dst_address_Sv, s);
	if (v.change_address_index != 0)
		write_field_varint(6, v.change_address_index, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignAddOutputResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.public_key = read_string(&s, e);
		else if (field_number == 2 && field_type == 2)
			v.encrypted_secret = read_string(&s, e);
		else if (field_number == 3 && field_type == 0)
			v.encrypted_address_type = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddOutputResponse &v) {
	std::string s;
	if (!v.public_key.empty())
		write_field_string(1, v.public_key, s);
	if (!v.encrypted_secret.empty())
		write_field_string(2, v.encrypted_secret, s);
	if (v.encrypted_address_type != 0)
		write_field_varint(3, v.encrypted_address_type, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignAddExtraRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.extra_chunk = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignAddExtraRequest &v) {
	std::string s;
	if (!v.extra_chunk.empty())
		write_field_string(1, v.extra_chunk, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStepARequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.output_secret_hash_arg = read_string(&s, e);
		else if (field_number == 2 && field_type == 0)
			v.address_index = read_varint(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepARequest &v) {
	std::string s;
	if (!v.output_secret_hash_arg.empty())
		write_field_string(1, v.output_secret_hash_arg, s);
	if (v.address_index != 0)
		write_field_varint(2, v.address_index, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStepAResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.sig_p = read_string(&s, e);
		else if (field_number == 2 && field_type == 2)
			v.y = read_string(&s, e);
		else if (field_number == 3 && field_type == 2)
			v.z = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepAResponse &v) {
	std::string s;
	if (!v.sig_p.empty())
		write_field_string(1, v.sig_p, s);
	if (!v.y.empty())
		write_field_string(2, v.y, s);
	if (!v.z.empty())
		write_field_string(3, v.z, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStepAMoreDataRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.data_chunk = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepAMoreDataRequest &v) {
	std::string s;
	if (!v.data_chunk.empty())
		write_field_string(1, v.data_chunk, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignGetC0Request &v, iterator s, iterator e) {
	while (s != e) {
		auto m          = read_varint(&s, e);
		auto field_type = static_cast<unsigned>(m & 7);
		skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignGetC0Request &v) {
	std::string s;
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignGetC0Response &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.c0 = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignGetC0Response &v) {
	std::string s;
	if (!v.c0.empty())
		write_field_string(1, v.c0, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStepBRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.output_secret_hash_arg = read_string(&s, e);
		else if (field_number == 2 && field_type == 0)
			v.address_index = read_varint(&s, e);
		else if (field_number == 3 && field_type == 2)
			v.my_c = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepBRequest &v) {
	std::string s;
	if (!v.output_secret_hash_arg.empty())
		write_field_string(1, v.output_secret_hash_arg, s);
	if (v.address_index != 0)
		write_field_varint(2, v.address_index, s);
	if (!v.my_c.empty())
		write_field_string(3, v.my_c, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinSignStepBResponse &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 2)
			v.my_rr = read_string(&s, e);
		else if (field_number == 2 && field_type == 2)
			v.rs = read_string(&s, e);
		else if (field_number == 3 && field_type == 2)
			v.ra = read_string(&s, e);
		else if (field_number == 4 && field_type == 2)
			v.encryption_key = read_string(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinSignStepBResponse &v) {
	std::string s;
	if (!v.my_rr.empty())
		write_field_string(1, v.my_rr, s);
	if (!v.rs.empty())
		write_field_string(2, v.rs, s);
	if (!v.ra.empty())
		write_field_string(3, v.ra, s);
	if (!v.encryption_key.empty())
		write_field_string(4, v.encryption_key, s);
	return s;
}

void read(::hw::trezor::messages::qcoin::qCoinStartProofRequest &v, iterator s, iterator e) {
	while (s != e) {
		auto m            = read_varint(&s, e);
		auto field_type   = static_cast<unsigned>(m & 7);
		auto field_number = static_cast<unsigned>(m >> 3);
		if (field_number == 1 && field_type == 0)
			v.data_size = read_varint_t<uint32_t>(&s, e);
		else
			skip_by_type(field_type, &s, e);
	}
}

std::string write(const ::hw::trezor::messages::qcoin::qCoinStartProofRequest &v) {
	std::string s;
	if (v.data_size != 0)
		write_field_varint(1, v.data_size, s);
	return s;
}

}  // namespace protobuf
