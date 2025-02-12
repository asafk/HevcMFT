#include "stdafx.h"
#include "Decoder.h"

Decoder::Decoder():
m_decoderS(NULL)
{
}

Decoder::~Decoder()
{
	SAFE_DELETE(m_decoderS);
}

bool Decoder::setDecoderStrategy(IDecoderStrategy* strategy)
{
	if(strategy != NULL){
		SAFE_DELETE(m_decoderS);
		m_decoderS = strategy;
	}

	return m_decoderS != NULL ? true : false;
}

bool Decoder::init(std::string codecName, DWORD pixel_format)
{
	return m_decoderS != NULL ?  m_decoderS->init(codecName, pixel_format) : false;
}

bool Decoder::release()
{
	return m_decoderS != NULL ?  m_decoderS->release() : false;
}

long Decoder::get_last_error()
{
	return m_decoderS != NULL ? m_decoderS->get_last_error() : ERR_DECODE_OK;	
}

void Decoder::flush()
{
	m_decoderS != NULL ? m_decoderS->flush(): (void)true;
}

bool Decoder::decode(unsigned char* in, int in_size, void*& out, int pitch)
{
	return m_decoderS != NULL ? m_decoderS->decode(in,in_size,out,pitch) : false;
}
