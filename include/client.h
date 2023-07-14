#pragma once

#include <cstdint>

struct unit;

namespace d2_protocol {
	struct packet_header;
}

typedef void(__cdecl* UpdateItemLocationExternalSignature)(uint32_t itemId, uint32_t x, uint32_t y, uint8_t page);

namespace item_mover {
	class client {
	public:
		client();

		void init();
		
		void handle_packet(d2_protocol::packet_header* packet) const;
	private:
		static unit* get_client_unit(uint32_t type, uint32_t guid);

		void handle_item_move(d2_protocol::packet_header* packet) const;

		UpdateItemLocationExternalSignature UpdateItemLocationExternal = nullptr;
	};
}