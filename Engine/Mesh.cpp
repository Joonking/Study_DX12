#include "pch.h"
#include "Mesh.h"
#include "Engine.h"

void Mesh::Init(vector<Vertex>& vec)
{
	_vertexCount = static_cast<uint32>(vec.size());
	uint32 bufferSize = _vertexCount * sizeof(Vertex);

	//어떤 용도로 사용할지 설정 : D3D12_HEAP_TYPE_UPLOAD =ㄴ
	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	//버퍼 사이즈 만큼 버퍼 만들기
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	//CreateCommittedResource 이걸로 GPU에 사용할 공간을 할당 받음.
	DEVICE->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_vertexBuffer));

	//_vertexBuffer 는 램에 있는 공간이 아닌 GPU에 공간을 가리키는 애임.
	//해당 공간에 데이터를 복사하려면 2가지 단계를 거침. 
	//Map 과 Unmap

	// Copy the triangle data to the vertex buffer.
	void* vertexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_vertexBuffer->Map(0, &readRange, &vertexDataBuffer);
	::memcpy(vertexDataBuffer, &vec[0], bufferSize);
	_vertexBuffer->Unmap(0, nullptr);

	// Initialize the vertex buffer view.
	_vertexBufferView.BufferLocation = _vertexBuffer->GetGPUVirtualAddress();
	_vertexBufferView.StrideInBytes = sizeof(Vertex); // 정점 1개 크기
	_vertexBufferView.SizeInBytes = bufferSize; // 버퍼의 크기	
}

void Mesh::Render()
{
	CMD_LIST->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CMD_LIST->IASetVertexBuffers(0, 1, &_vertexBufferView); // Slot: (0~15)

	//TODO: 
	// CMD_LIST->SetComputeRootConstantBufferView(0, );

	CMD_LIST->DrawInstanced(_vertexCount, 1, 0, 0);
}