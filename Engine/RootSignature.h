#pragma once

//��༭ / ����

// CPU���� GPU�� ���ָ� �ñ�µ�
// ����� ����ϰڴ� ��� ���� �̶�� ������ ��ħ

//��� ����, �������͸� ����ϰڴٴ� ���� ������ִ°���. 

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	//ComPrt�� �Ǿ��ִ� ��κ��� �͵��� GPU���� ��� ���� ��û�� �� �����.
	//�׸��� GPU ���ο��� ��ü�� ������.
	ComPtr<ID3D12RootSignature>	_signature;
};





