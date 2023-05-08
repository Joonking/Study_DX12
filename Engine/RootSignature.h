#pragma once

//계약서 / 결재

// CPU에서 GPU로 외주를 맡기는데
// 어떤것을 사용하겠다 라는 서명 이라는 절차를 거침

//어떠한 버퍼, 레지스터를 사용하겠다는 것을 명시해주는거임. 

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	//ComPrt로 되어있는 대부분의 것들은 GPU에게 어떠한 것을 요청할 때 사용함.
	//그리고 GPU 내부에서 객체가 생성됨.
	ComPtr<ID3D12RootSignature>	_signature;
};





