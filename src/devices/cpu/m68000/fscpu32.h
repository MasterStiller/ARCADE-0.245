// license:BSD-3-Clause
// copyright-holders:Karl Stenerud
#ifndef MAME_CPU_M68000_FSCPU32_H
#define MAME_CPU_M68000_FSCPU32_H

#pragma once

#include "m68kcommon.h"

class fscpu32_device : public m68000_base_device
{
public:
	// construction/destruction
	fscpu32_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);

	virtual std::unique_ptr<util::disasm_interface> create_disassembler() override;

	virtual u32 execute_min_cycles() const noexcept override { return 2; }
	virtual u32 execute_max_cycles() const noexcept override { return 158; }

	// device-level overrides
	virtual void device_start() override;

protected:
	fscpu32_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock,
						const device_type type, u32 prg_data_width, u32 prg_address_bits, address_map_constructor internal_map);
};

DECLARE_DEVICE_TYPE(FSCPU32, fscpu32_device)

#endif
