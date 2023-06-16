
//Constant Buffer�� ����Ұǵ� �������ʹ� b0�� b1�� ����ҰŴ�
cbuffer TEST_B0 : register(b0)
{
    float4 offset0;
};

cbuffer TEST_B1 : register(b1)
{
    float4 offset1;
};

Texture2D tex_0 : register(t0);

SamplerState sam_0 : register(s0);

//vs�ܰ迡�� ����� �͵��� �ش� �ڷ������� ����. 
struct VS_IN
{
    float3 pos : POSITION;
    float4 color : COLOR;
    float2 uv : TEXCOORD;
};

//vs�ܰ迡�� ���� ������� ���� �ڷ��� 
struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
    float2 uv : TEXCOORD;
};

//VS(Vertex Shader)�ܰ迡�� ���ؾ������� ����
//vs�ܰ�� ������ ��� ��ȭ������ ���ϴ� �ܰ�
VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT) 0;

    //input���� ���� 3������ ��(float3)�� �״�� �־��ְ�, ������ ���� 1�� ä����
    //output.pos�� �־����.
    output.pos = float4(input.pos, 1.f);
    output.color = input.color;
    output.uv = input.uv;

    return output;
}

//PS(Pixel Shader) �ܰ迡�� �� �ؾ������� ����
//ps�ܰ�� ������ �����ִ� �ܰ���.
float4 PS_Main(VS_OUT input) : SV_Target
{
    float4 color = tex_0.Sample(sam_0, input.uv);
    return color;
}

